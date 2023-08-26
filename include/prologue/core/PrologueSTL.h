#pragma once

#include "Platform.h"

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

namespace prologue
{
    template<typename _Ty>
    class Allocator : public std::allocator<_Ty>
    {
    public:
        allocator() : std::allocator<_Ty>() {}
        allocator(const allocator<_Ty>& rhs) : std::allocator<_Ty>(rhs) {}
        template<class _Other> allocator(const allocator<_Other>& rhs) : std::allocator<_Ty>(rhs) {}

        template<class _Other> struct rebind // convert an allocator<_Ty> to an allocator <_Other>
        {
            typedef allocator<_Other> other;
        };
        void deallocate(typename std::allocator<_Ty>::pointer _Ptr, typename std::allocator<_Ty>::size_type)
        {
            Free((void*)_Ptr);
        }
        typename std::allocator<_Ty>::pointer allocate(typename std::allocator<_Ty>::size_type _Count)
        { // allocate array of _Count el ements
            return static_cast<typename std::allocator<_Ty>::pointer>((Alloc(_Count * sizeof(_Ty))));
        }
    };

    template<typename _Ty, int _Alignment>
    class AlignedAllocator : public std::allocator<_Ty>
    {
    public:
        allocator() : std::allocator<_Ty>() {}
        allocator(const allocator<_Ty>& rhs) : std::allocator<_Ty>(rhs) {}
        template<class _Other> allocator(const allocator<_Other>& rhs) : std::allocator<_Ty>(rhs) {}

        template<class _Other> struct rebind // convert an allocator<_Ty> to an allocator <_Other>
        {
            typedef allocator<_Other> other;
        };
        void deallocate(typename std::allocator<_Ty>::pointer _Ptr, typename std::allocator<_Ty>::size_type)
        {
            AlignedFree((void*)_Ptr);
        }
        typename std::allocator<_Ty>::pointer allocate(typename std::allocator<_Ty>::size_type _Count)
        { // allocate array of _Count el ements
            return static_cast<typename std::allocator<_Ty>::pointer>((AlignedAlloc(_Count * sizeof(_Ty), _Alignment)));
        }
    };

    template<typename _Ty, typename _Alloc = Allocator<_Ty>>
    using Vector = std::vector<_Ty, _Alloc>;

    template<typename _Ty, typename _Alloc = Allocator<_Ty>>
    using List = std::list<_Ty, _Alloc>;

    template<typename _Ty, typename _Alloc = Allocator<_Ty>>
    using Deque = std::deque<_Ty, _Alloc>;

    template<typename _Ty, typename _Container = Deque<_Ty>>
    using Queue = std::queue<_Ty, _Container>;

    template<typename _Ty, typename _Container = Deque<_Ty>>
    using Stack = std::stack<_Ty, _Container>;

    template<typename _Elem>
    using CharTraits = std::char_traits<_Elem>;

    template<typename _Elem, typename _Traits = CharTraits<_Elem>, typename _Alloc = Allocator<_Elem>>
    using BasicString = std::basic_string<_Elem, _Traits, _Alloc>;

    using String = BasicString<char, CharTraits<char>, Allocator<char>>;
    using WString = BasicString<wchar_t, CharTraits<wchar_t>, Allocator<wchar_t>>;

    template<typename _Ty1, typename _Ty2>
    using Pair = std::pair<_Ty1, _Ty2>;

    template<typename _Ty>
    using Less = std::less<_Ty>;

    template<typename _Ty>
    using Greater = std::greater<_Ty>;

    template<typename _Kty>
    using Hash = std::hash<_Kty>;

    template<typename _Ty>
    using EqualTo = std::equal_to<_Ty>;

    template<typename _Kty, typename _Pr = Less<_Kty>, typename _Alloc = Allocator<_Kty>>
    using Set = std::set<_Kty, _Pr, _Alloc>;

    template<typename _Kty, typename _Hasher = Hash<_Kty>, typename _Keyeq = EqualTo<_Kty>, typename _Alloc = Allocator<_Kty>>
    using UnorderedSet = std::unordered_set<_Kty, _Hasher, _Keyeq, _Alloc>;

    template<typename _Kty, typename _Ty, typename _Pr = Less<_Kty>, typename _Alloc = Allocator<Pair<const _Kty, _Ty>>>
    using Map = std::map<_Kty, _Ty, _Pr, _Alloc>;

    template<typename _Kty, typename _Ty, typename _Hasher = Hash<_Kty>, typename _Keyeq = EqualTo<_Kty>, typename _Alloc = Allocator<Pair<const _Kty, _Ty>>>
    using UnorderedMap = std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>;

    template<typename _Kty, typename _Ty, typename _Pr = Less<_Kty>, typename _Alloc = Allocator<Pair<const _Kty, _Ty>>> 
    using MultiMap = std::multimap<_Kty, _Ty, _Pr, _Alloc>;

    template<typename _Kty, typename _Ty, typename _Hasher = Hash<_Kty>, typename _Keyeq = EqualTo<_Kty>, typename _Alloc = Allocator<Pair<const _Kty, _Ty>>>
    using UnorderedMultiMap = std::unordered_multimap<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>;

} // namespace prologue