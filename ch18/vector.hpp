#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>

class vector {
public:
    explicit vector(int sz);
    vector(std::initializer_list<double> lst);
    ~vector();

    // copy sementics
    vector(const vector &rhs);
    vector& operator=(const vector &rhs);

    // move sementics
    vector(vector &&rhs);
    vector& operator=(vector &&rhs); 
    
    double& operator[](int n);
    const double& operator[](int n) const;

    int size() const;

private:
    int m_sz;
    double *m_elem;
};


#endif
