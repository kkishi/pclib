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
  void Insert(int64_t v) {
    if (int b = bits(v); b > bits_) {
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
      n = &(*n)->children[(v >> i) & 1];
    }
    if (!*n) *n = new Node;
    ++(*n)->size;
  }
  void Erase(int64_t v) {
    assert(bits(v) <= bits_);
    Node** n = &root_;
    for (int i = bits_ - 1; i >= 0; --i) {
      Node** c = &(*n)->children[(v >> i) & 1];
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
  int64_t MinElement(int64_t x = 0) const { return FindByOrder(0, x); }
  int64_t MaxElement(int64_t x = 0) const { return FindByOrder(Size() - 1, x); }
  int64_t FindByOrder(int64_t o, int64_t x = 0) const {
    assert(o < Size());
    const Node* n = root_;
    int64_t v = 0;
    for (int i = bits_ - 1; i >= 0; --i) {
      int64_t L = (x >> i) & 1;
      Node* l = n->children[L];
      int ls = l ? l->size : 0;
      if (o < ls) {
        v |= L << i;
        n = l;
      } else {
        int64_t R = 1 - L;
        v |= R << i;
        n = n->children[R];
        o -= ls;
        assert(n);
      }
    }
    return v;
  }
  int Size() const { return root_ ? root_->size : 0; }

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
