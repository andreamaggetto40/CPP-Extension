template <typename T>
class double_list{
    struct node{
        struct node* prev;
        T info;
        struct node* next;
    };

    struct node* head; struct node* tail;

    public:
        double_list();

        void append(const T item);
        void print();
        void print_reverse();
};

template<typename T>
double_list<T>::double_list(){
    head = tail = nullptr;
}

template<typename T>
void double_list<T>::append(const T item){
    struct node* to_append = new node(); to_append->prev = nullptr; to_append->info = item; to_append->next = nullptr;

    if(!head and !tail){
        head = tail = to_append;
    }
    else{
        tail->next = to_append; to_append->prev = tail; tail = tail->next;
    }
}

template<typename T>
void double_list<T>::print(){
    for(; head; std::cout<<head->info<<std::endl,head = head->next);
}

template<typename T>
void double_list<T>::print_reverse(){
    for(; tail; std::cout<<tail->info<<std::endl,tail = tail->prev);
}