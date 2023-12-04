class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        int writeIndex = 0; // Use an index to write compressed characters

        int srclength = chars.size();
        for(int index = 0; index < srclength; index++) {
            chars[writeIndex++] = chars[index]; // Copy the character

            count = 1;
            while(index < srclength - 1 && chars[index] == chars[index + 1]) {
                count++;
                index++;
            }

            if(count > 1) {
                string CountToString = to_string(count);
                for(char c : CountToString) {
                    chars[writeIndex++] = c; // Write the count as characters
                }
            }
        }
        return writeIndex; // Return the length of the compressed array
    }
};
