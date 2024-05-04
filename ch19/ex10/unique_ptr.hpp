#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

class default_delete {
public:
    template <typename T>
    void operator()(T *p) const
    {
        delete p;
    }
};

template <typename T, typename Deleter = default_delete>
class unique_ptr {
public:
    explicit unique_ptr(T *ptr = nullptr, const Deleter &deleter = Deleter{});
    ~unique_ptr();

    unique_ptr(const unique_ptr &) = delete;
    unique_ptr& operator=(const unique_ptr &) = delete;

    unique_ptr(unique_ptr &&rhs) noexcept;
    unique_ptr& operator=(unique_ptr &&rhs) noexcept;

    T& operator*() const noexcept;
    T* operator->() const noexcept;

    T* release() noexcept;

private:
    T *m_ptr;
    Deleter m_deleter;
};

template <typename T, typename Deleter>
unique_ptr<T,Deleter>::unique_ptr(T *ptr, const Deleter &deleter)
    : m_ptr{ptr},
      m_deleter{deleter}
{}

template <typename T, typename Deleter>
unique_ptr<T,Deleter>::~unique_ptr()
{
    m_deleter(m_ptr);
}

template <typename T, typename Deleter>
unique_ptr<T,Deleter>::unique_ptr(unique_ptr &&rhs) noexcept
    : m_ptr{rhs.m_ptr},
      m_deleter{rhs.m_deleter}
{
    rhs.m_ptr = nullptr;
}

template <typename T, typename Deleter>
unique_ptr<T,Deleter>& unique_ptr<T,Deleter>::operator=(unique_ptr &&rhs) noexcept
{
    if(this == &rhs) {
        return *this;
    }
    m_deleter(m_ptr);
    m_ptr = rhs.m_ptr;
    m_deleter = rhs.m_deleter;
    rhs.m_ptr = nullptr;
    return *this;
}

template <typename T, typename Deleter>
T& unique_ptr<T,Deleter>::operator*() const noexcept
{
    return *m_ptr;
}

template <typename T, typename Deleter>
T* unique_ptr<T,Deleter>::operator->() const noexcept
{
    return m_ptr;
}

template <typename T, typename Deleter>
T* unique_ptr<T,Deleter>::release() noexcept
{
    auto *old_ptr{m_ptr};
    m_ptr = nullptr;
    return old_ptr;
}

#endif


