using std::cout; using std::endl;

template<typename T>
class list{
    struct node{
        T info;
        struct node* next;
    };

    struct node* head;
    struct node* tail;

    void create_recursion(struct node* cell){
        if(cell){
            create_recursion(cell->next);
            cout<<cell->info<<endl;
        }
    };


    public:
        list();


        void append(const T& item);
        size_t size();
        void print();
        unsigned period();
        void make_circular();
        void merge_list(const list<T>& l1, const list<T>& l2);
        void print_reverse();
        string concat(int pos,int len);

        struct node* operator=(list<T> to_copy);
};

template<typename T>
list<T>::list(){    
    head = tail = nullptr;
}

template<typename T>
void list<T>::append(const T& item){
    struct node* to_append = new node(); to_append->info = item; to_append->next = nullptr;

    if(!head){
        head = tail = to_append;
    }
    else{
        tail->next = to_append;
        tail = tail->next;
    }
}

template<typename T>
size_t list<T>::size(){
    size_t counter{0};

    for(; head; ++counter, head = head->next);

    return counter;
}

template<typename T>
void list<T>::print(){
    for(; head; cout<<head->info<<endl,head = head->next);
}

/*template<typename T>
struct node* list<T>::operator=(list<T> to_copy){
    
}*/

template<typename T>
unsigned list<T>::period(){
    unsigned frequency{0};

    if(head){
        frequency = 1; struct node* check{head}; struct node* iterator{head->next};

        for(; iterator and iterator->info != check->info; ++frequency,iterator = iterator->next);
    }

    return frequency;
}

template<typename T>
void list<T>::make_circular(){
    tail->next = head;
}

template<typename T>
void list<T>::merge_list(const list<T>& l1, const list<T>& l2){
    list<T> output{};

    if(l1.head and l2.head){
        struct node* it1{l1.head}; struct node* it2{l2.head}; 

        while(it1 or it2){
            if(it1->info < it2->info or (it1 and !it2)){output.append(it1->info); it1 = it1->next;}
            else {output.append(it2->info); it2 = it2->next;}
        }
    }

    output.print();
}

template<typename T>
void list<T>::print_reverse(){    
    create_recursion(head);
}

template<typename T>
string list<T>::concat(int pos, int len){
    string output{}; struct node* iterator{head};

    for(size_t i{0}; i < pos and iterator; ++i, iterator = iterator->next);
    for(size_t i{0}; i < len and iterator; ++i, output += iterator->info, iterator = iterator->next);

    return output;

}

