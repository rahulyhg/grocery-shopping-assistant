#include <iostream>
#include <string>
#include <regex>
#include <sstream> 

using namespace std;

string nutrientinfo_regex_search(std::string& input){

    std::stringstream s;
    std::string jsonString;


    /*
    "Nutrition Information per I0Og product (approx..)1 Carbohydrates 70g Sugars 24.5g
      Protein 7g Fat 20g Saturated fatty acids 9g Mono unsaturated fatty acids 8.2g
       Poly unsaturated fatty acids 2.7g Trans fatty acids Og Cholesterol Omg Energy 488kcal "

    */

    //std::regex rgx("[A-Z][a-z]+[ ][(]?[g|3]?[)]?[ ][0-9|O]+[a-z]*");
    std::regex rgx("[A-Z][a-z]+[ ][0-9|o|O]+[.]?[0-9|o|O]*[a-z]*");
    std::smatch match;

    std::smatch nut_match;
    //Carbohydrates (g) 70g
    std::regex carbRegex("[C][a][r][a-z]*[ ]([0-9|o|O]+[.]?[0-9|o|O]*[a-z]*)");
    std::regex sugarsRegex("[S][u][g][a-z]*[ ]([0-9|o|O]+[.]?[0-9|o|O]*[a-z]*)");
    std::regex proteinRegex("[P][r][o][a-z]*[ ]([0-9|o|O]+[.]?[0-9|o|O]*[a-z]*)");
    std::regex fatsRegex("[F][a][t][s]?[ ]([0-9|o|O]+[.]?[0-9|o|O]*[a-z]*)");
    std::regex energyRegex("[E][n][e][a-z]*[ ]([0-9|o|O]+[.]?[0-9|o|O]*[a-z]*)");   

    std::smatch nut_match2;

    regex regexOto0("[O]");

    double carbsValue = 0;
    double sugarsValue = 0;
    double proteinValue = 0;
    double fatsValue = 0;
    double energyValue = 0;

    while (std::regex_search(input, match, rgx)){
        //std::cout << "Match : " << match[0] << endl;

        //for (auto m : match)
          //std::cout << "  submatch " << m << '\n';

        if(std::regex_search(match[0].str(), nut_match, carbRegex)){

           //std::cout << "\tIts Carbohydrates" << endl;
           //std::cout << "\tOld Carbohydrates = " << nut_match[1].str() << endl;

           string OremovedString = regex_replace(nut_match[1].str(), regexOto0, "0");

           std::regex regex3("([0-9]+)[3]");
           std::regex regexTh("([0-9]+)[t][h]");

           if(std::regex_search(OremovedString, nut_match2, regex3)){

                carbsValue = ::atof(nut_match2[1].str().c_str());
                //std::cout << "\tNew Carbohydrates = " << carbsValue << "g" << endl;
           } else if(std::regex_search(OremovedString, nut_match2, regexTh)){

                regex thRegex("[t][h]");
                string thRelpacedString = regex_replace(OremovedString, thRegex, "5");
                carbsValue = ::atof(thRelpacedString.c_str());
                //std::cout << "\tNew Carbohydrates = " << carbsValue << "g" << endl;
           } else {
                regex regexG("[g]");
                string GremovedString = regex_replace(OremovedString, regexG, "");
                carbsValue = ::atof(GremovedString.c_str());
                //std::cout << "\tNew Carbohydrates = " << carbsValue << "g" << endl;
           }

        }else if (std::regex_search(match[0].str(), nut_match, sugarsRegex)){

            //std::cout << "\tIts Sugars" << endl;
            //std::cout << "\tOld Sugars = " << nut_match[1].str() << endl;

            string OremovedString = regex_replace(nut_match[1].str(), regexOto0, "0");

            std::regex regex3("([0-9]+)[3]");
            std::regex regexTh("([0-9]+)[t][h]");

            if(std::regex_search(OremovedString, nut_match2, regex3)){

                sugarsValue = ::atof(nut_match2[1].str().c_str());
                //std::cout << "\tNew Sugars = " << sugarsValue << "g" << endl;
            } else if(std::regex_search(OremovedString, nut_match2, regexTh)){

                regex thRegex("[t][h]");
                string thRelpacedString = regex_replace(OremovedString, thRegex, "5");
                sugarsValue = ::atof(thRelpacedString.c_str());
                //std::cout << "\tNew Sugars = " << sugarsValue << "g" << endl;
            } else {
                regex regexG("[g]");
                string GremovedString = regex_replace(OremovedString, regexG, "");
                sugarsValue = ::atof(GremovedString.c_str());
                //std::cout << "\tNew Sugars = " << sugarsValue << "g" << endl;
            }

        }else if (std::regex_search(match[0].str(), nut_match, proteinRegex)){

            //std::cout << "\tIts Protein" << endl;
            //std::cout << "\tOld Protein = " << nut_match[1].str() << endl;

            string OremovedString = regex_replace(nut_match[1].str(), regexOto0, "0");

            std::regex regex3("([0-9]+)[3]");
            std::regex regexTh("([0-9]+)[t][h]");

            if(std::regex_search(OremovedString, nut_match2, regex3)){

                proteinValue = ::atof(nut_match2[1].str().c_str());
                //std::cout << "\tNew Protein = " << proteinValue << "g" << endl;
            } else if(std::regex_search(OremovedString, nut_match2, regexTh)){

                regex thRegex("[t][h]");
                string thRelpacedString = regex_replace(OremovedString, thRegex, "5");
                proteinValue = ::atof(thRelpacedString.c_str());
                //std::cout << "\tNew Protein = " << proteinValue << "g" << endl;
            } else {
                regex regexG("[g]");
                string GremovedString = regex_replace(OremovedString, regexG, "");
                proteinValue = ::atof(GremovedString.c_str());
                //std::cout << "\tNew Protein = " << proteinValue << "g" << endl;
            }
            
        }else if (std::regex_search(match[0].str(), nut_match, fatsRegex)){

            //std::cout << "\tIts Fats" << endl;
            //std::cout << "\tOld Fats = " << nut_match[1].str() << endl;

            string OremovedString = regex_replace(nut_match[1].str(), regexOto0, "0");

            std::regex regex3("([0-9]+)[3]");
            std::regex regexTh("([0-9]+)[t][h]");

            if(std::regex_search(OremovedString, nut_match2, regex3)){

                fatsValue = ::atof(nut_match2[1].str().c_str());
                //std::cout << "\tNew Fats = " << fatsValue << "g" << endl;
            } else if(std::regex_search(OremovedString, nut_match2, regexTh)){

                regex thRegex("[t][h]");
                string thRelpacedString = regex_replace(OremovedString, thRegex, "5");
                fatsValue = ::atof(thRelpacedString.c_str());
                //std::cout << "\tNew Fats = " << fatsValue << "g" << endl;
            } else {
                regex regexG("[g]");
                string GremovedString = regex_replace(OremovedString, regexG, "");
                fatsValue = ::atof(GremovedString.c_str());
                //std::cout << "\tNew Fats = " << fatsValue << "g" << endl;
            }
            
        }else if (std::regex_search(match[0].str(), nut_match, energyRegex)){

            //std::cout << "\tIts Energy" << endl;
            //std::cout << "\tOld Energy = " << nut_match[1].str() << endl;

            string OremovedString = regex_replace(nut_match[1].str(), regexOto0, "0");

            std::regex regex3("([0-9]+)[3]");
            std::regex regexTh("([0-9]+)[t][h]");

            if(std::regex_search(OremovedString, nut_match2, regex3)){

                energyValue = ::atof(nut_match2[1].str().c_str());
                //std::cout << "\tNew Energy = " << energyValue << "kcal" << endl;
            } else if(std::regex_search(OremovedString, nut_match2, regexTh)){

                regex thRegex("[t][h]");
                string thRelpacedString = regex_replace(OremovedString, thRegex, "5");
                energyValue = ::atof(thRelpacedString.c_str());
                //std::cout << "\tNew Energy = " << energyValue << "kcal" << endl;
            }else {
                regex regexG("[k][a-z]*");
                string GremovedString = regex_replace(OremovedString, regexG, "");
                energyValue = ::atof(GremovedString.c_str());
                //std::cout << "\tNew Energy = " << energyValue << "kcal" << endl;
            }
            
        }
         input = match.suffix().str();
    }

    s << "{\
    \"Energy\" : " << energyValue << ",\
    \"Carbohydrates\" : " << carbsValue << ",\
    \"Sugars\" : " << sugarsValue << ",\
    \"Protein\" : " << proteinValue << ",\
    \"Fats\" : " << fatsValue << "\
    }";
    jsonString = s.str();

    return jsonString;            

}

int main(int argc, const char * argv[]){

    std::string jsonNutrients;

    std::string inputString(argv[1]);

    jsonNutrients = nutrientinfo_regex_search(inputString);

    cout << " { \"jsonNutrients\" : " << jsonNutrients << "}" << endl;

    return 0;
}

