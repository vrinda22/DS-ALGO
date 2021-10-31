# Question Link https://leetcode.com/problems/implement-trie-prefix-tree/

class Node:
    
    def __init__(self, val = None):
        
        self.val = val
        self.conn = []
        

class Trie:

    def __init__(self):
        
        self.trie = Node()

    def insert(self, word: str) -> None:
        
        cur = self.trie
        for char in word:
            for node in cur.conn:
                if node.val == char:
                    cur = node
                    break
            else:
                node = Node(char)
                cur.conn.append(node)
                cur = node
        else:
            cur.conn.append(Node("$"))
    

    def search(self, word: str) -> bool:
        
        cur = self.trie
        for char in word:
            for node in cur.conn:
                if node.val == char:
                    cur = node
                    break
            else:
                return False
        else:
            for node in cur.conn:
                if node.val == "$":
                    return True
            else:
                return False
        

    def startsWith(self, prefix: str) -> bool:
        
        cur = self.trie
        for char in prefix:
            for node in cur.conn:
                if node.val == char:
                    cur = node
                    break
            else:
                return False
        else:
            return True
        

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)