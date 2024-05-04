#include "std_lib_facilities.h"

// COMMENT:
// This was harder then I expected. Feel free to test this for more inputs to see if it is really correct.
//
// To recap: The mode in a sequence of elements (here, positive integers) where its frequency appears the most.
// For example: {1, 3, 2, 3, 3, 4} --> (1, 2, 3, 3, 3, 4} --> 3
// Now, what if there is more than one answer? There can be two positive integers that appear the most. Having two// modes is called bimodal. Having more than two modes is called multimodal. Because of this, this requires
// extra thinking. 

vector<int> find_mode(const vector<int> &values)
{
    if(values.size() == 1) return {values[0]}; 
    
    vector<int> modes;
    int max_cnt = 1;
    int curr_cnt = 1;
    int mode = -1;
    for(int i = 0; i != values.size() - 1; ++i) {
        if(values[i] == values[i+1]) {
            ++curr_cnt;
        }
        else {
            if(max_cnt < curr_cnt) {
                max_cnt = curr_cnt;
                mode = values[i];
                modes = {mode}; 
            }
            else if(max_cnt == curr_cnt && max_cnt != 1) {
                mode = values[i];
                modes.push_back(mode);
            }
            curr_cnt = 1;
        }
    }
    if(max_cnt < curr_cnt) {
        max_cnt = curr_cnt;
        mode = values[values.size()-1];
        modes = {mode}; 
    }
    else if(max_cnt == curr_cnt && max_cnt != 1) {
        mode = values[values.size() - 1];
        modes.push_back(mode);
    }
    return modes;
}
int main()
{
    try {
       
        cout << "Read a sequence of positive integers seperated by a space. (Enter \'|\' to stop):\n";
        vector<int> values;
        for(int value; cin >> value;) {
            if(value < 1) cout << value << " is not a positive integer. Try again.\n";
            else          values.push_back(value);
        }
        if(values.size() == 0) error("no values were read");
        
        sort(values);

        vector<int> modes = find_mode(values);
        if(modes.size() == 0) {
            cout << "There exists no modes in the sequence.\n";
        }
        else {
            for(int m : modes) {
                cout << m << ' ';
            }
            cout << '\n';
        }

        return 0;
    }
    
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
