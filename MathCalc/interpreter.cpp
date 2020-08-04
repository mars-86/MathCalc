#include "interpreter.h"

Interpreter::Interpreter()
{

}

Interpreter::~Interpreter()
{

}

int Interpreter::interpret(ParseTree& tree)
{
	tree.traverse("infix");
	resolv(tree, tree.get_parse_tree());
	std::cout << "\nRes: ";
	tree.traverse("infix");
	return 0;
}

// TODO
// make function to format numbers (interger or float)

void Interpreter::resolv(ParseTree& tree, Binop* root)
{
	if (root == nullptr) return;
	resolv(tree, root->left);
	resolv(tree, root->right);
	//tree.traverse("infix");
	std::cout << std::endl;
	if (is_operator(root->val)) {
		char buff_temp[128];
		if (strcmp((char*)root->val, "+") == 0)
			sprintf_s(buff_temp, 128, "%.2f", (atof((char*)root->left->val) + atof((char*)root->right->val)));
		else if (strcmp((char*)root->val, "-") == 0)
			sprintf_s(buff_temp, 128, "%.2f", (atof((char*)root->left->val) - atof((char*)root->right->val)));
		else if (strcmp((char*)root->val, "*") == 0)
			sprintf_s(buff_temp, 128, "%.2f", (atof((char*)root->left->val) * atof((char*)root->right->val)));
		else if (strcmp(root->val, "/") == 0)
			sprintf_s(buff_temp, 128, "%.2f", (atof((char*)root->left->val) / atof((char*)root->right->val)));
		else
			sprintf_s(buff_temp, 128, "%.2f", pow(atof((char*)root->left->val), atof((char*)root->right->val)));

		free(root->left), free(root->right), free(root->val);
		root->left = root->right = nullptr, root->val = nullptr;
		size_t valen = strlen(buff_temp);
		root->val = (char*)malloc((valen + 1) * sizeof(char));
		memcpy_s(root->val, (valen + 1), buff_temp, valen), root->val[valen] = '\0';
		//std::cout << root->val << std::endl;
	}
}

bool Interpreter::is_operator(const char* c)
{
	if ((strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0 || strcmp(c, "^") == 0))
		return true;
	return false;
}