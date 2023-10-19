#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


std::string openThisText(std::string file){
    std::ifstream ifc;
    std::string text{""};
    ifc.open(file);
    if(!ifc.is_open()){
        std::cout<<"Error i cant find file\n";
    }else{
        while(!ifc.eof()){
            std::string full;
            ifc>>full;
            text += full;
        }
    }
    ifc.close();
    return text;
}

int howManyChars(std::string a,std::string letter){
    int howMany{0};
    for(int i = 0; i < a.size(); ++i){
        if(letter.at(0) == a.at(i)){
            ++howMany;
        }
    }
    return howMany;
}

void howManyDifferentCharacters(std::string myStr){
    char for_cycle = 'a';
for(for_cycle; for_cycle != 'z'; for_cycle++){
    std::string answer;
    answer += for_cycle;
    std::cout<<for_cycle<<" -> "<<howManyChars(myStr,answer)<<" times\n";
    answer.clear();
}
    for_cycle = 'z';
    std::string answer;
    answer += for_cycle;
    std::cout<<for_cycle<<" -> "<<howManyChars(myStr,answer)<<" times\n";
    answer.clear();
}


int main()
{
    std::string buffer = openThisText("example.txt");
    howManyDifferentCharacters(buffer);
}
