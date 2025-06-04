class Solution {
public:
    string addBinary(string a, string b) {
        // the strategy is to just add the end elements and hold a carry
        int aPtr = a.size() - 1;
        int bPtr = b.size() - 1;
        bool carryBit = 0;

        // store output string in reverse due to pushback O(1)
        string outputRev;

        // while either index is valid or a carry bit is in the mix
        while(aPtr >= 0 || bPtr >= 0 || carryBit){
            
            // update the current value only if it is a valid index
            // implicitly update index pointer on call
            int aVal = (aPtr >= 0) ? a[aPtr--] - '0' : 0;
            int bVal = (bPtr >= 0) ? b[bPtr--] - '0' : 0;

            // int from 0-3
            int bitVal = aVal + bVal + carryBit;
            
            // set the bit to mod of 2 for base 2
            // ex. 0 % 2 -> 0, 1 % 2 -> 1, 2 % 2 -> 0, 3 % 2 -> 1
            outputRev.push_back((bitVal % 2) + '0'); // convert back to char

            // update the carry
            carryBit = bitVal > 1;
        }

        // quick rev string
        std::reverse(outputRev.begin(), outputRev.end());
        
        return outputRev;
    }
};