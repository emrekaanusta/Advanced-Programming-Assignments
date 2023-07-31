#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// on the second tour,,,,, there are lots of errors.

using namespace std;

int main() {
    string fileName, s, query, filename1;
    int a = 0, c = 0, numLines = 0, linenum = 0;
    ifstream input;
    int number = 0;
    int f = 0, counter = 0, counter2 = 0;


    vector<vector<char>> shapeMatrix;


    cout<<"Please enter the file name: "<< endl;
    cin>> filename1;

    fileName = "C:\\Users\\My\\CLionProjects\\untitled2\\cmake-build-debug\\" + filename1;
    // fileName = filename1;

    input.open(fileName.c_str());

    if  (input.fail()){
        while (input.fail()){
            input.close();
            cout << "Could not open the file. Please enter a valid file name: " << endl;
            cin >> filename1;
            fileName = "C:\\Users\\My\\CLionProjects\\untitled2\\cmake-build-debug\\" + filename1;
            input.open(fileName);}
    }

    while (getline(input, s)){
        numLines++;
        if   (  (s.length() != a) && ( c > 0 )  || (s.length() == 0) )
        {
            cout << "Erroneous file content. Program terminates." << endl;
            return 0;
        }

        for (int i = 0; i < s.length(); i++){
            char var = s[i];
            if (( var != '-' ) && ( var != '#' )){
                cout << "Erroneous file content. Program terminates." << endl;
                return 0;
            }
        }

        a = s.length();
        c++;
    }
    input.close();

    vector<vector<char>> mat(numLines, vector<char>(a));

    input.open(fileName);

    cout << "The matrix file contains: " << endl;

    while (getline(input, s)){
        for (unsigned int i = 0; i < s.length(); i++){
            char variable = s[i];
            mat[linenum][i] = variable;


        }
        linenum++;
        cout << s << endl;
    }



    cout << "Enter the string query for a shape, or \"Quit\" to terminate the program: " << endl;
    cin >> query;

    // i couldnt find a simpler way to initialize the vector



    while (query != "Quit") {
        f = 0;
        int max = 0;
        counter = 0;
        int index1 = query.find("/");
        int counter4 = 0;
        string querybackup = query;

        while (index1 != string::npos) {   // if / in the query
            counter2 = 0;
            string newquery = query.substr(0, index1);  // new query example 2s1b1s
            for (int i = 0; i < newquery.length(); i++) {   // matrix placement of the query
                if (newquery[i] == 's') {
                    for (int k = 0; k < number; k++) {

                        counter++;
                    }
                    counter4 += counter;
                    counter = 0;
                }
                if (newquery[i] == 'b') {
                    for (int k = 0; k < number; k++) {

                        counter++;// inpt[f][k] = '-';   // something wrong it does not work with pushback
                    }
                    counter4 += counter;
                    counter = 0;
                }
                if (isdigit(newquery[i])) {   // if a number is dialed
                    number = newquery[i] - '0';

                }

            }

            if (counter4 > max){ max = counter4;}
            counter4 = 0;
            query = query.substr(index1 + 1, query.length() - index1 - 1); // new query with the substr ed one
            f++; // next row
            index1 = query.find("/");
        }
        string newquery = query; // new query example 2s11s



        for (int i = 0; i < newquery.length(); i++) {   // matrix placement of the query
            if (newquery[i] == 's') {
                for (int k = 0; k < number; k++) {

                    counter ++;
                }
                counter4 += counter;
                counter = 0;
            }
            if (newquery[i] == 'b') {
                for (int k = 0; k < number; k++) {

                    counter ++;
                }
                counter4 += counter;
                counter = 0;
            }
            if (isdigit(newquery[i])) {   // if a number is dialed
                number = newquery[i] - '0';
            }
        }
        if (counter4 > max){ max = counter4;}

        // we found the row and column numbers of inpt

        vector<vector<char>> inpt(f+1, vector<char>(max));  // how many columns of inpt


        // now old query comes back

        query = querybackup;
        f = 0;
        counter = 0;
        index1 = query.find("/");

        while (index1 != string::npos) {   // if / in the query
            counter2 = 0;
            string newquery = query.substr(0, index1);  // new query example 2s1b1s
            for (int i = 0; i < newquery.length(); i++) {   // matrix placement of the query
                if (newquery[i] == 's') {
                    for (int k = 0; k < number; k++) {
                        inpt[f][counter2+k] = 's';
                        counter++;
                    }
                    counter2 += counter;
                    counter = 0;
                }
                if (newquery[i] == 'b') {
                    for (int k = 0; k < number; k++) {
                        inpt[f][counter2+k] = '-';
                        counter++;// inpt[f][k] = '-';   // something wrong it does not work with pushback
                    }
                    counter2 += counter;
                    counter = 0;
                }
                if (isdigit(newquery[i])) {   // if a number is dialed
                    number = newquery[i] - '0';

                }

            }


            counter2 = 0;
            query = query.substr(index1 + 1, query.length() - index1 - 1); // new query with the substr ed one
            f++; // next row
            index1 = query.find("/");
        }
        newquery = query; // new query example 2s11s

        int number7 = 0;
        int counter3 = 0;

        for (int i = 0; i < newquery.length(); i++) {   // matrix placement of the query
            if (newquery[i] == 's') {
                for (int k = 0; k < number7; k++) {
                    inpt[f][counter3+k] = 's';
                    counter++;
                }
                counter3 += counter;
                counter = 0;
            }
            if (newquery[i] == 'b') {
                for (int k = 0; k < number7; k++) {
                    inpt[f][counter3+k] = '-';
                    counter++;
                }
                counter3 += counter;
                counter = 0;
            }
            if (isdigit(newquery[i])) {   // if a number is dialed
                number7 = newquery[i] - '0';
            }
        }
        // cout << inpt[0][0] << inpt [0][1] << inpt[1][0] << inpt[1][1] << endl;  // for debuging purposes

        // hopefully our inpt matrix is working without any failures.
         // now input matrix is handled and txt files is matrixed, we need to find the placements.
        // right now if the input is like 1s1b1s/1s1b matrix is inpt[0][0] = 's' ,inpt[0][1] = '-', inpt[0][2] = 's' etc
        // now we should compare if there is an available spot for these input by compraing the mat matrix
        // don't forget to ask the possible places again

        // now compare part


        // ask again if they wanna know
        // cout << mat[0][0] << mat[0][1] << mat[0][2] << mat[0][3]  << mat[0][4] << endl ; // başa 5 tane boşluk koyuyo imdat
        string place;
        int sum1 = 0,sum2 = 0;
        string sum3, sum4;
        vector<vector<string>> allplaces;

        // check if the input matrix is bigger than or not to the txt matrix
        if (!((inpt.size() > mat.size()) or (inpt[0].size() > mat[0].size()))) {
            for (int j = 0; j < mat.size() - inpt.size() + 1; j++) {   // txt file matrix row
                for (int l = 0; l < mat[0].size() - inpt[0].size() + 1; l++) {    // txt file matrix column
                    vector<string> placements; // possible places
                    bool correct = true;
                    for (int p = 0; p < inpt.size(); p++) {      // input matrix row
                        for (int t = 0; t < inpt[0].size(); t++) {   // input matrix col
                            if (inpt[p][t] == 's' and
                                mat[j + p][l + t] == '#') {  // if input is star and that position is full
                                correct = false;
                            }
                            if (inpt[p][t] == 's' and mat[j + p][l + t] == '-') {
                                sum1 = j + p;
                                sum2 = l + t;
                                sum3 = to_string(sum1);
                                sum4 = to_string(sum2);
                                place = "(" + sum3 + "," + sum4 + ")";
                                placements.push_back(place);
                            }
                        }

                    }
                    if (correct) { // if all the matrix are matched
                        allplaces.push_back(placements);
                    } else {
                        placements.size();
                    }

                }
            }
        }
        if (allplaces.size() == 0){
            cout << "No placements found." << endl;
        }

        else {
            for (int i = 0; i < allplaces.size(); i++){
                cout << "Placement number " << i+1 << ":" << endl;
                for (int k = 0; k < allplaces[i].size(); k++){
                    cout << allplaces[i][k] << " " ;
                }
                cout << endl;
            }

        }

        cout << "Enter the string query for a shape, or \"Quit\" to terminate the program: " << endl;
        cin >> query;}


    if (query == "Quit") {
        return 0;
    }



    return 0;

}