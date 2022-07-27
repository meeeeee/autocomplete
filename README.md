# autocomplete
A C++ implementation of a trie-based autocompleter.\
The trie (trie.cpp) is stored as an $N\times |A|$ array $\texttt{trie}$, where $A$ is the string alphabet used and $N$ is the longest string considered, of some datatype that stores at least $|A|$ bits (a uint, ull, or bitset for smaller alphabets and a bitset for larger alphabets). It checks for the existence of and adds a given string in $\mathcal{O}(n)$.\
We check if there exists an edge from the $k$ th character $c_k$ to the $k+1$ th character $c_{k+1}$ by checking if the $c_k$ th bit of $\texttt{trie[}k+1\texttt{][}c_{k+1}\texttt{]}$ is 1 and iteratively repeat this for every character in the string when considering whether a string or superstring (string with given string as prefix) has already been processed, returning false if any of the checks return false.
