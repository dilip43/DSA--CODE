// Implementation:
// 1 - Count the no. of nodes in the given BST
// using Morris Inorder Traversal.
// 2 - Then Perform Morris Inorder traversal one
// more time by counting nodes and by checking if
// count is equal to the median point.
// To consider even no. of nodes an extra pointer
// pointing to the previous node is used.

int countNodes(Node* root) {
   Node* current, pre;
   int count = 0;
   if (root == NULL) return count;
   current = root;
   while (current != NULL) {
      if (current->left == NULL) {
         count++;
         current = current->right;
      }
      else {
         prev = current->left;
         while (pre->right != NULL && pre->right != current)
            pre = pre->right;

         if (pre->right == NULL)
         {
            pre->right = current;
            current = current->left;
         }
         else
         {
            pre->right = NULL;
            count++;
            current = current->right;
         }
      }
   }
   return count;
}

int findMedian(Node* root) {
   if (!root) return 0;
   int count = countNodes(root);
   int currCount = 0;
   Node *current = root, *pre, *prev;
   while (current != NULL) {
      if (current->left == NULL) {
         currCount++;
         //check if the current node is the median point
         //odd case
         if (count % 2 != 0 && currCount == (count + 1) / 2)
            return prev->data;
         //even case
         if (count % 2 == 0 && currCount = (count / 2) + 1)
            return (prev->data + current->data) / 2;

         prev = current;
         current = current->right;
      }
      else {
         pre = current->left;
         while (pre->right != NULL)
            pre = pre->right;

         if (pre->right == NULL) {
            pre->right = current;
            current = current->left;
         }
         else {
            pre->right = NULL;
            prev = pre;
            currCount++;

            if (count % 2 != 0 && currCount == (count + 1) / 2)
               return current->data;

            else if (count % 2 == 0 && currCount = (count / 2) + 1)
               return (prev->data + current->data) / 2;

            prev = current;
            current = current->right;
         }

      }
   }
}