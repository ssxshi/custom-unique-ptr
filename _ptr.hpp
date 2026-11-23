#ifndef CUSTPTR_H
#define CUSTPTR_H

template<typename T>
class cst_ptr{
    private:
        T* data;

    public:
        cst_ptr();
        explicit cst_ptr(T* d);
        ~cst_ptr();

        cst_ptr(const cst_ptr&) = delete;
        cst_ptr& operator=(const cst_ptr&) = delete;

        cst_ptr(cst_ptr&& other) noexcept;
        cst_ptr& operator=(cst_ptr&& other) noexcept;

        T& operator*() const noexcept;
        T* operator->() const noexcept;
        explicit operator bool() const noexcept;

        T* release() noexcept;
        void reset();
        void reset(T* new_data);
        T* get() const noexcept;
};

template<typename T>
cst_ptr<T>::cst_ptr() : data(nullptr) {}

template<typename T>
cst_ptr<T>::cst_ptr(T* d) : data(d) {}

template<typename T>
cst_ptr<T>::~cst_ptr(){
    delete data;
    data = nullptr;
}

template<typename T>
cst_ptr<T>::cst_ptr(cst_ptr&& other) noexcept :data(other.data){
    other.data = nullptr;
}

template<typename T>
cst_ptr<T>& cst_ptr<T>::operator=(cst_ptr&& other) noexcept {
    if (this == &other) return *this;

    delete data;

    data = other.data;
    other.data = nullptr;

    return *this;
}

template<typename T>
T& cst_ptr<T>::operator*() const noexcept{
    return *data;
}

template<typename T>
T* cst_ptr<T>::operator->() const noexcept{
    return data;
}

template<typename T>
cst_ptr<T>::operator bool() const noexcept{
    return data != nullptr;
}

template<typename T>
T* cst_ptr<T>::release() noexcept {
    T* to_ret = data;
    data = nullptr;
    return to_ret;
}

template<typename T>
void cst_ptr<T>::reset(){
    delete data;
    data = nullptr;
}

template<typename T>
void cst_ptr<T>::reset(T* new_data){
    if (data == new_data) return;

    delete data;
    data = new_data;
}

template<typename T>
T* cst_ptr<T>::get() const noexcept {
    return data;
}

#endif
