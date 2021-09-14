#include <cassert>
#include <cstdint>
#include <iostream>

class BinaryTrie {
 private:
  struct Node {
    int size = 0;
    Node* children[2] = {};
  };

 public:
  BinaryTrie() {}
  void Insert(int64_t x) {
    if (int b = bits(x); b > bits_) {
      if (root_) {
        for (int i = 0; i < (b - bits_); ++i) {
          Node* n = new Node;
          n->size = root_->size;
          n->children[0] = root_;
          root_ = n;
        }
      }
      bits_ = b;
    }
    Node** n = &root_;
    for (int i = bits_ - 1; i >= 0; --i) {
      if (!*n) *n = new Node;
      ++(*n)->size;
      n = &(*n)->children[(x >> i) & 1];
    }
    if (!*n) *n = new Node;
    ++(*n)->size;
  }
  void Erase(int64_t x) {
    assert(bits(x) <= bits_);
    Node** n = &root_;
    for (int i = bits_ - 1; i >= 0; --i) {
      Node** c = &(*n)->children[(x >> i) & 1];
      assert(*c);
      if (--(*n)->size == 0) {
        *n = nullptr;
        delete (*n);
      }
      n = c;
    }
    if (--(*n)->size == 0) {
      *n = nullptr;
      delete (*n);
    }
  }
  int64_t MinElement() const { return FindByOrder(0); }
  int64_t MaxElement() const { return FindByOrder(Size() - 1); }
  int64_t FindByOrder(int64_t o) const {
    assert(o < root_->size);
    const Node* n = root_;
    int x = 0;
    for (int i = bits_ - 1; i >= 0; --i) {
      Node* l = n->children[0];
      if (l && o < l->size) {
        n = l;
      } else {
        x |= 1LL << i;
        n = n->children[1];
        o -= l ? l->size : 0;
        assert(n);
      }
    }
    return x;
  }
  int Size() const { return root_->size; }

  void Debug(Node* n, int depth, int x) {
    if (!n) return;
    std::cout << '(' << x << ":" << n->size;
    Debug(n->children[0], depth + 1, x);
    Debug(n->children[1], depth + 1, x | (1LL << (bits_ - 1 - depth)));
    std::cout << ")";
  }
  void Debug() {
    Debug(root_, 0, 0);
    std::cout << std::endl;
  }

 private:
  static int bits(int64_t x) { return x == 0 ? 0 : (64 - __builtin_clzll(x)); }
  Node* root_ = nullptr;
  int bits_ = 0;
};
