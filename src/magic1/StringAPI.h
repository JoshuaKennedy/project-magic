#pragma once

extern "C" __declspec (dllexport) char* strndup (const char *s, size_t n);
extern "C" __declspec (dllexport) char* substring(const char* str, size_t begin, size_t len);
