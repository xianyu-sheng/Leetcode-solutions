#include <iostream>
#include <cstring>
#include <unistd.h>      // 提供 close()
#include <arpa/inet.h>   // 提供 sockaddr_in, inet_ntoa, htons 等
#include <sys/socket.h>  // 提供 socket(), bind(), listen(), accept()

int main() {
    // 1. 创建监听 socket (IPv4, TCP 协议)
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        std::cerr << "创建 socket 失败!" << std::endl;
        return -1;
    }

    // 2. 配置服务器地址结构体并绑定 (Bind)
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // 监听任意本地 IP
    server_addr.sin_port = htons(8080);       // 端口号，htons() 将主机字节序转为网络字节序(大端序)

    if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "绑定端口失败!" << std::endl;
        close(listen_fd);
        return -1;
    }

    // 3. 开始监听 (Listen)
    // 这里的 5 是 TCP 全连接队列 (accept queue) 的建议长度
    if (listen(listen_fd, 5) == -1) { 
        std::cerr << "监听失败!" << std::endl;
        close(listen_fd);
        return -1;
    }
    std::cout << "服务器已启动，正在监听端口 8080..." << std::endl;

    // 4. 接收客户端连接 (Accept)
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // ⚠️ 注意：默认情况下，accept 是【阻塞】的。没有客户端连接时，线程会在这里死等。
    int client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd == -1) {
        std::cerr << "接收连接失败!" << std::endl;
        close(listen_fd);
        return -1;
    }
    std::cout << "客户端连接成功! IP: " << inet_ntoa(client_addr.sin_addr) << std::endl;

    // 5. 接收和处理消息 (Echo 回显逻辑)
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        
        // ⚠️ 注意：默认情况下，recv 也是【阻塞】的。如果客户端不发数据，线程卡在这里。
        ssize_t bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

        if (bytes_read > 0) {
            std::cout << "收到客户端消息: " << buffer << std::endl;
            // 将收到的消息原样发回给客户端
            send(client_fd, buffer, bytes_read, 0);
        } else if (bytes_read == 0) {
            std::cout << "客户端正常断开连接 (发送了 FIN 包)。" << std::endl;
            break;
        } else {
            std::cerr << "读取数据出错!" << std::endl;
            break;
        }
    }

    // 6. 释放资源
    close(client_fd);
    close(listen_fd);
    return 0;
}
