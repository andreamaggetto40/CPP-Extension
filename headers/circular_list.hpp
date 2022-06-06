
using std::cout; using std::endl; using std::string;

template <typename T>
class circular_list{
    struct node{
        struct node* next;
        T info;
    };

    struct node* head; struct node* tail;

    bool positive(struct node* cell){
        return cell->info > 0 and positive(cell->next);

        
    }

    public:
        circular_list();


        size_t size();
        void append(T item);
        void print();
        void find_tail();
        void insert_at(const std::string& str, int index);

        bool is_any_positive();
};

template<typename T>
circular_list<T>::circular_list(){
    head = tail = nullptr;
}

template<typename T>
void circular_list<T>::append(T item){
    struct node* appender = new node(); appender->info = item; appender->next = appender;

    if(!head and !tail){
        head = tail = appender;
    }
    else{
        appender->next = head; tail->next = appender; tail = tail->next;
    }
}



template<typename T>
size_t circular_list<T>::size(){
    size_t size{0}; struct node* iterator{head};

    for(; iterator != tail; ++size, iterator = iterator->next);

    return size + 1;


};

template<typename T>
void circular_list<T>::print(){
    bool check{true}; node* iterator{head};

    for(size_t i{0}; i < size(); cout<<iterator->info<<endl, ++i, iterator = iterator->next);
}

template<typename T>
void circular_list<T>::insert_at(const string& str, int index){
    struct node* iterator{head};

    for(int i{0}; i < index - 1; ++i, iterator = iterator->next);

    struct node* to_add = new node(); to_add->info = str; to_add->next = iterator->next;
    tail = iterator;
    iterator->next = to_add;
    head = to_add;
}

template<typename T>
bool circular_list<T>::is_any_positive(){      
    return positive(head);
}