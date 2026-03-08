void* my_memmove(void* dest, const void* src, size_t n) {
    if (dest == nullptr || src == nullptr) return nullptr;
    
    char* d = static_cast<char*>(dest);
    const char* s = static_cast<const char*>(src);
    
    if (d > s && d < s + n) {
        // 内存重叠，从后往前拷贝
        d = d + n - 1;
        s = s + n - 1;
        while (n--) {
            *d-- = *s--;
        }
    } else {
        // 无重叠，从前往后拷贝
        while (n--) {
            *d++ = *s++;
        }
    }
    return dest;
}
