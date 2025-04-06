namespace boost {
  template<typename T> struct hash;

  template<> struct hash<bool>;
  template<> struct hash<char>;
  template<> struct hash<signed char>;
  template<> struct hash<unsigned char>;
  template<> struct hash<wchar_t>;
  template<> struct hash<char16_t>;
  template<> struct hash<char32_t>;
  template<> struct hash<short>;
  template<> struct hash<unsigned short>;
  template<> struct hash<int>;
  template<> struct hash<unsigned int>;
  template<> struct hash<long>;
  template<> struct hash<unsigned long>;
  template<> struct hash<long long>;
  template<> struct hash<unsigned long long>;
  template<> struct hash<float>;
  template<> struct hash<double>;
  template<> struct hash<long double>;
  template<> struct hash<std::string>;
  template<> struct hash<std::wstring>;
  template<> struct hash<std::u16string>;
  template<> struct hash<std::u32string>;
  template<typename T> struct hash<T*>;
 // template<> struct hash<std::type_index>;

  // Support functions (Boost extension).
  template<typename T> void hash_combine(size_t &, T const&);
  template<typename It> std::size_t hash_range(It, It);
  template<typename It> void hash_range(std::size_t&, It, It);

  // Overloadable hash implementation (Boost extension).
  std::size_t hash_value(bool);
  std::size_t hash_value(char);
  std::size_t hash_value(signed char);
  std::size_t hash_value(unsigned char);
  std::size_t hash_value(wchar_t);
  std::size_t hash_value(char16_t);
  std::size_t hash_value(char32_t);
  std::size_t hash_value(short);
  std::size_t hash_value(unsigned short);
  std::size_t hash_value(int);
  std::size_t hash_value(unsigned int);
  std::size_t hash_value(long);
  std::size_t hash_value(unsigned long);
  std::size_t hash_value(long long);
  std::size_t hash_value(unsigned long long);
  std::size_t hash_value(float);
  std::size_t hash_value(double);
  std::size_t hash_value(long double);
  template<typename T> std::size_t hash_value(T* const&);
  template<typename T, unsigned N> std::size_t hash_value(T (&val)[N]);
  template<typename T, unsigned N> std::size_t hash_value(const T (&val)[N]);
  template<typename T, typename A> 
    std::size_t hash_value(std::vector<T, A> const&);
\
}