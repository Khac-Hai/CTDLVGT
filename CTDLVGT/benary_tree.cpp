#include <iostream>
#include <vector>

struct Node {
  char data;
  Node *left;
  Node *right;
  int key;
};

/**
 * @brief Tạo một node mới từ một node mẹ của cây nhị phân
 *
 * @param parent : node mẹ
 * @param value : giá trị node sẽ được tạo
 * @param lr : 'l' tạo node bên trái, 'r' tạo node phải
 * @return Con trỏ trỏ đến node vừa tạo
 */
Node* CreateNode(Node *parent, const int key, const char value, const char lr) {
  // Xin bộ nhớ một Node và khởi tạo Node
  Node *node = new Node;
  node->left = node->right = nullptr;
  node->data = value;
  node->key = key;

  if (parent == nullptr) {
    // TH1: parent == NULL, tức là cây rỗng
    return node;
  } else {
    // TH2: parent != NULL, cây không rỗng
    // Kiểm tra bên trái, bên phải của node parent là NULL hay không
    // nếu có node con ở bên trái hoặc phải thì bỏ qua
    Node *ptr;
    if (lr == 'l')
      ptr = parent->left;
    else if (lr == 'r')
      ptr = parent->right;
    else {
      std::cerr << "Error lr = " << lr << " not supported." << std::endl;
      delete node;
      return nullptr;
    }

    if (ptr != nullptr) {
      std::cerr << "Error: cannot create node with value " << value << std::endl;
      delete node;
      return nullptr;
    }

    if (lr == 'l') 
      parent->left = node;
    else if (lr == 'r')
      parent->right = node;
    return node;
  }
}

/**
 * @brief Xóa cây và giải phóng bộ nhớ
 *
 * @param root: Node gốc của cây cần xóa
 */
void DeleteTree(Node *root) {
  if (root == nullptr)
    return;
  DeleteTree(root->left);
  DeleteTree(root->right);
  delete root;
}

/**
 * @brief In nội dung cây ra màn hình sử dụng duyệt trước
 *
 * @param[in] root : Node gốc của cây
 */
void PreorderPrint(Node *root) {
  if (root == nullptr)
    return;
  std::cout << root->key << ":" << root->data << ", ";
  PreorderPrint(root->left);
  PreorderPrint(root->right);
}

/**
 * @brief In nội dung cây ra màn hình sử dụng duyệt giữa
 *
 * @param[in] root : Node gốc của cây
 */
void InorderPrint(Node *root) {
  if (root == nullptr)
    return;
  InorderPrint(root->left);
  std::cout << root->key << ":" << root->data << ", ";
  InorderPrint(root->right);
}

/**
 * @brief In nội dung cây ra màn hình sử dụng duyệt sau
 *
 * @param[in] root : Node gốc của cây
 */
void PostorderPrint(Node *root) {
  if (root == nullptr)
    return;
  PostorderPrint(root->left);
  PostorderPrint(root->right);
  std::cout << root->key << ":" << root->data << ", ";
}

/**
 * @brief Tạo danh sách các khóa của BST ở dạng duyệt giữa
 *
 * @param root Gốc của cây nhị phần đầu vào
 * @param key_list Một vector chứa danh sách các khóa ở dạng duyệt giữa cần tìm
 */
void GetInorderKeyList(Node *root, std::vector<int> &key_list) {
  if (root == nullptr)
    return;
  GetInorderKeyList(root->left, key_list);
  key_list.push_back(root->key);
  GetInorderKeyList(root->right, key_list);
}

/**
 * @brief Kiểm tra một cây có phải là cây nhị phân tìm kiếm
 *
 * @param root Gốc của một cây nhị phân có khóa
 * @return Trả về true nếu cây là BST, false trong trường hợp ngược lại
 */
bool CheckBST(Node *root) {
  std::vector<int> key_list;
  GetInorderKeyList(root, key_list);
  for (int i = 0; i < key_list.size()-1; ++i) {
    if (key_list[i] >= key_list[i+1]) 
      return false;
  }
  return true;
}

/**
 * @brief Tìm kiếm node với khóa cho trước
 *
 * @param root Gốc của cây BST
 * @param key Khóa cần tìm
 * @return Node có khóa cần tìm hoặc node lá có khóa gần nhất với khóa cần tìm
 */
Node *SearchNode(Node *root, const int key) {
  Node *ptr = root;
  Node *parent;

  if (root == nullptr)
    return nullptr;

  while (ptr != nullptr) {
    parent = ptr;
    if (key == ptr->key)
      return ptr;
    else if (key < ptr->key) {
      ptr = ptr->left;
    } else {
      // key > ptr->key
      ptr = ptr->right;
    }
  }
  return parent;
}

/**
 * @brief Thêm node vào cây BST và vẫn đảm bảo cây là cây BST
 *
 * @param root Gốc của cây BST 
 * @param key Khóa của node cần thêm 
 * @param value Dữ liệu của node cần thêm
 */
void InsertNode(Node *root, const int key, const char value) {
  Node *ptr = SearchNode(root, key);
  if (ptr->key == key)
    return;
  else if (key < ptr->key)
    CreateNode(ptr, key, value, 'l');
  else // key > ptr->key
    CreateNode(ptr, key, value, 'r');
}

Node* SearchData(Node *root, const char val) {
  Node *ptr = root;
  Node *parent;
  while (ptr != nullptr) {
    parent = ptr;
    if (val == ptr->data) {
      return ptr;
    } else if (val < ptr->data) {
      ptr = ptr->left;  
    } else {
      ptr = ptr->right;  
    }
  }
  return parent;
}


int main() {
  Node *root = CreateNode(nullptr, 20, 'a', 'r');
  Node *ptr = root;

  // tạo cây con trái
  ptr = CreateNode(ptr, 10, 'b', 'l');
  CreateNode(ptr, 5, 'd', 'l');
  CreateNode(ptr, 17, 'e', 'r');
  ptr = ptr->left;
  CreateNode(ptr, 7, 'i', 'r');

  // tạo cây con phải
  ptr = CreateNode(root, 30, 'c', 'r');
  CreateNode(ptr, 48, 'g', 'r');
  ptr = CreateNode(ptr, 26, 'f', 'l');
  CreateNode(ptr, 23, 'f', 'l');
  CreateNode(ptr, 28, 'f', 'r');
  ptr = root->right->right;
  CreateNode(ptr, 50, 'l', 'r');

  std::cout << "Kiểm tra nội dung cây duyệt trước" << std::endl;
  PreorderPrint(root);
  std::cout << std::endl;

  std::cout << "Kiểm tra nội dung cây duyệt giữa" << std::endl;
  InorderPrint(root);
  std::cout << std::endl;

  std::cout << "Kiểm tra nội dung cây duyệt sau" << std::endl;
  PostorderPrint(root);
  std::cout << std::endl;

  std::vector<int> keys;
  GetInorderKeyList(root, keys);
  std::cout << "Ket qua GetInorderKeyList: " << std::endl;
  for (auto v: keys)
    std::cout << v << ", ";
  std::cout << std::endl;

  std::cout << "Kiem tra cay co phai la BST: ";
  if (CheckBST(root))
    std::cout << "DUNG LA cay BST" << std::endl;
  else
    std::cout << "KHONG PHAI cay BST" << std::endl;

  std::cout << "TIM KIEM: ";
  ptr = SearchNode(root, 29);
  std::cout << ptr->key << ":" << ptr->data <<std::endl;

  std::cout << "THEM NODE: " << std::endl;
  InorderPrint(root);
  std::cout << std::endl;
  InsertNode(root, 28, 'z');
  InorderPrint(root);
  std::cout << std::endl;
  

  std::cout << "TIM KIEM DATA: ";
  ptr = SearchData(root, 'l');
  if (ptr != nullptr) {
  std::cout << ptr->key << ":" << ptr->data << std::endl;
  } else {
  std::cout << "Khong tim thay du lieu can tim." << std::endl;
}
  DeleteTree(root);
  root = nullptr;
}
