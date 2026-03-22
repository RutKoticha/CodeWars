/**
 * @file 297_Serialize_and_Deserialize_Binary_Tree.cpp
 * @author Rut Koticha
 * @date 2025-10-30
 */

#include <string>
#include <queue>
#include <vector>
#include <charconv>

#ifdef LOCAL_RUN
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Codec {
private:
  std::vector<std::string_view> Tokenize(const std::string& data_string, char token_delimiter = '#');
  TreeNode* ConstructTreeFromTokens(std::vector<std::string_view> tokens);
  int GetIntValueFromStringView(std::string_view view);
  TreeNode* CreateNodeFromToken(std::string_view token);

public:
  std::string serialize(TreeNode* root);
  TreeNode* deserialize(std::string serialized);
};

std::vector<std::string_view> Codec::Tokenize(const std::string& data_string, char token_delimiter)
{
  std::string_view data_view(data_string);
  std::vector<std::string_view> tokens;

  for (size_t iterator = 0; iterator < data_view.size(); iterator++)
  {
    size_t begin = iterator;

    while (data_view.at(iterator) != token_delimiter)
      iterator++;

    tokens.emplace_back(data_view.substr(begin, iterator - begin));
  }

  return tokens;
}

TreeNode* Codec::ConstructTreeFromTokens(std::vector<std::string_view> tokens)
{
  int root_value = GetIntValueFromStringView(tokens.at(0));
  TreeNode* root = new TreeNode(root_value);

  std::queue<TreeNode*> queue;
  queue.push(root);

  for (size_t i = 1; i < tokens.size(); i += 2)
  {
    TreeNode* parent = queue.front();
    queue.pop();

    std::string_view left_token = tokens.at(i);
    std::string_view right_token = tokens.at(i + 1);

    if (left_token != "null")
    {
      TreeNode* left_node = CreateNodeFromToken(tokens.at(i));
      parent->left = left_node;
      queue.push(left_node);
    }

    if (right_token != "null")
    {
      TreeNode* right_node = CreateNodeFromToken(tokens.at(i + 1));
      parent->right = right_node;
      queue.push(right_node);
    }
  }

  return root;
}

int Codec::GetIntValueFromStringView(std::string_view view)
{
  int int_value;
  auto [pointer, error_code] = std::from_chars(view.data(), view.data() + view.size(), int_value);

  if (error_code == std::errc::invalid_argument)
    return -1;

  return int_value;
}

TreeNode* Codec::CreateNodeFromToken(std::string_view token)
{
  int node_value = GetIntValueFromStringView(token);
  return new TreeNode(node_value);
}

std::string Codec::serialize(TreeNode* root)
{
  if (!root)
    return "null#";

  std::string serialized = "";
  std::queue<TreeNode*> queue;
  queue.push(root);

  while (!queue.empty())
  {
    TreeNode* node = queue.front();
    queue.pop();

    if (!node)
    {
      serialized += "null#";
      continue;
    }

    serialized += std::to_string(node->val) + '#';

    queue.push(node->left);
    queue.push(node->right);
  }

  return serialized;
}

TreeNode* Codec::deserialize(std::string serialized)
{
  if (serialized == "null#")
    return nullptr;

  std::vector<std::string_view> tokens = Tokenize(serialized);
  return ConstructTreeFromTokens(tokens);
}
