#ifndef INCLUDED_CONTAINER
#define INCLUDED_CONTAINER

#include <cstddef>
#include <tr1/functional>
#include <iostream>

namespace BloombergLP {
namespace trnx {

  template <class T, class U>
  class HashMap {
  private:
    struct Node {
      T key;
      U value;
      Node* _next;
    };
    enum {
      SIZE = 10
    };
    Node** buckets;
    int (*hashFunction)(T);
    HashMap(const HashMap& other); // = delete
    HashMap& operator=(const HashMap& other); // = delete
    HashMap(); // = delete

  public:
    HashMap(int (*hashFunction)(T));
    ~HashMap();
    void put(T key, U value);
    U get(T key);
  };

  template <class T, class U>
  HashMap<T, U>::HashMap(int (*funct)(T)) : buckets(new Node*[SIZE]), hashFunction(funct)
  {
    for (int i = 0; i != SIZE; ++i) {
      buckets[i] = NULL;
    }
  }

  template <class T, class U>
  HashMap<T, U>::~HashMap()
  {
    for (int i = 0; i != SIZE; ++i) {
      Node* node = buckets[i];
      while (node) {
        Node* temp = node;
        node = node->_next;
        std::cout << "Delete element: " << temp->key <<"\n";
        delete temp;
      }
    }
    std::cout << "Delete array" << "\n";
    delete [] buckets;
  }

  template <class T, class U>
  void HashMap<T, U>::put(T key, U value)
  {
    int hash = hashFunction(key);
    int bucketId = hash % SIZE;
    std::cout << "Key: " << key << " Bucket: " << bucketId << "\n" ;
    Node* newNode = new Node;
    newNode->key = key;
    newNode->value = value;
    newNode->_next = NULL;
    if (!buckets[bucketId]) {
      buckets[bucketId] = newNode;
    }
    else {
      Node * node = buckets[bucketId];
      while (node->_next) {
        node = node->_next;
      }
      node->_next = newNode;
    }
  }

  template <class T, class U>
  U HashMap<T, U>::get(T key)
  {
    int hash = hashFunction(key);
    int bucketId = hash % SIZE;
    if (buckets[bucketId]) {
      Node* node = buckets[bucketId];
      while (node) {
        if (node->key == key) {
          return node->value;
        }
        node = node->_next;
      }
      return U();
    }
    else {
      return U();
    }
  }

}
}

#endif
