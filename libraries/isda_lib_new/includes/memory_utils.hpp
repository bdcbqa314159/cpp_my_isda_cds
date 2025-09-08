#pragma once
#ifndef MEMORY_UTILS_HPP
#define MEMORY_UTILS_HPP

#include <cstdlib>
#include <cstring>

#include "cmemory.hpp"
// #include "code_cpp.hpp"

template <typename T>
inline T* New() {
  return static_cast<T*>(JpmcdsMallocSafe(sizeof(T)));
}

template <typename T>
inline T* NewArray(size_t n) {
  return static_cast<T*>(JpmcdsMallocSafe(sizeof(T) * n));
}

template <typename T>
inline void FreeArray(T* ptr) {
  JpmcdsFreeSafe(ptr);
}

// --- Type-safe replacement for COPY_ARRAY ---
template <typename T>
inline void CopyArray(T* dst, const T* src, size_t n) {
  memcpy(static_cast<void*>(dst), static_cast<const void*>(src), n * sizeof(T));
}

// --- Type-safe replacement for FREE ---
template <typename T>
inline void Free(T* ptr) {
  JpmcdsFreeSafe(static_cast<void*>(ptr));
}

// --- Deprecated functions (with warnings) ---
template <typename T>
[[deprecated("Use New<T>() instead")]]
inline T* NEW() {
  return New<T>();
}

template <typename T>
[[deprecated("Use NewArray<T>(n) instead")]]
inline T* NEW_ARRAY(size_t n) {
  return NewArray<T>(n);
}

template <typename T>
[[deprecated("Use FreeArray(ptr) instead")]]
inline void FREE_ARRAY(T* ptr) {
  FreeArray(ptr);
}

template <typename T>
[[deprecated("Use CopyArray<T>(dst, src, n) instead")]]
inline void COPY_ARRAY(T* dst, const T* src, size_t n) {
  CopyArray<T>(dst, src, n);
}

template <typename T>
[[deprecated("Use Free(ptr) instead")]]
inline void FREE(T* ptr) {
  Free(ptr);
}

#endif  // MEMORY_UTILS_HPP