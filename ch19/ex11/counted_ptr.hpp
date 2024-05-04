#ifndef CCOUNTED_PTR_HPP
#define COUNTED_PTR_HPP

template <typename T>
class counted_ptr {
public:
    counted_ptr() = default;
    explicit counted_ptr(const T &value);
    ~counted_ptr();

    counted_ptr(const counted_ptr &rhs);
    counted_ptr& operator=(const counted_ptr &rhs);

    counted_ptr(counted_ptr &&rhs) noexcept;
    counted_ptr& operator=(counted_ptr &&rhs) noexcept;

    T& operator*() const noexcept;
    T* operator->() const noexcept;

    int use_count() const noexcept;

private:
    T *m_ptr{};
    int *m_use_count{};
};

template <typename T>
counted_ptr<T>::counted_ptr(const T &value)
    : m_ptr{new T{value}},
      m_use_count{new int{1}} { }

template <typename T>
counted_ptr<T>::~counted_ptr()
{
    if(m_use_count) {
        if(--*m_use_count == 0) {
            delete m_ptr;
            delete m_use_count;
        }
    }
}

template <typename T>
counted_ptr<T>::counted_ptr(const counted_ptr &rhs)
    : m_ptr{rhs.m_ptr},
      m_use_count{rhs.m_use_count}
{
    ++*m_use_count;
}

template <typename T>
counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr &rhs)
{
    if(this == &rhs) {
        return *this;
    }
    if(m_ptr && --*m_use_count == 0) {
        delete m_ptr;
        delete m_use_count;
    }
    m_ptr = rhs.m_ptr;
    m_use_count = rhs.m_use_count;
    ++*m_use_count;
    return *this;
}

template <typename T>
counted_ptr<T>::counted_ptr(counted_ptr &&rhs) noexcept
    : m_ptr{rhs.m_ptr},
      m_use_count{rhs.m_use_count}
{
    rhs.m_ptr = rhs.m_use_count = nullptr;
}

template <typename T>
counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr &&rhs) noexcept
{
    if(this == &rhs) {
        return *this;
    }
    if(m_ptr && --*m_use_count == 0) {
        delete m_ptr;
        delete m_use_count;
    }

    m_ptr = rhs.m_ptr;
    m_use_count = rhs.m_use_count;
    rhs.m_ptr = rhs.m_use_count = nullptr;
    return *this;
}

template <typename T>
inline int counted_ptr<T>::use_count() const noexcept
{
    return m_use_count ? *m_use_count : 0;
}

template <typename T>
inline T& counted_ptr<T>::operator*() const noexcept
{
    return *m_ptr;
}

template <typename T>
inline T* counted_ptr<T>::operator->() const noexcept
{
    return m_ptr;
}


#endif
