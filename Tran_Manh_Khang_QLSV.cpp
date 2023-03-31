    /*
    * File: Tran_Manh_Khang_QLSV.cpp
    * Author: Khang Trần
    * Date: 25/03/2023
    * Description: Chương trình quản lý sinh viên
    */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>

using namespace std;

class SinhVien {
private:
    uint8_t id;
    char studentName[20];
    char studentGender[4];
    uint8_t studentAge;
    float mathScore;
    float physicsScore;
    float chemistryScore;
    float averageScore;
    char studentPerformance[11];
public:
    SinhVien(const char name[], const char gender[], const uint8_t age, 
             float math, float physics, float chem); //Constructor
    void setStudentName(const char name[]);
    void setGender(const char gender[]);
    void setStudentAge(const uint8_t age);
    void setMathScore(float math);
    void setPhysicsScore(float physics);
    void setChemistryScore(float chem);
    uint8_t getID();
    char *getStudentName();
    char *getGender();
    uint8_t getStudentAge();
    float getMathScore();
    float getPhysicsScore();
    float getChemistryScore();
    float getAverageScore();
    char *getPerformance();
};
    /*
    *Function: ENTER_INFORMATION
    *Description: Hàm chung để nhập thông tin có điều kiện
    *Input: content, format, variable, condition
    */
#define ENTER_INFORMATION(content, format, variable, condition) \
do                                                              \
{                                                               \
    printf("%s", content);                                      \
    scanf(format, variable);                                    \
} while (condition)

    /* CREATE CONSTRUCTOR */
SinhVien::SinhVien(const char name[], const char gender[], const uint8_t age, 
                   float math, float physics, float chem) {
    static uint8_t id = 100; //Create the first id begin at 100
    SinhVien::id = id;
    id++; 
    strcpy(SinhVien::studentName, name);
    strcpy(SinhVien::studentGender, gender);
    SinhVien::studentAge = age;
    SinhVien::mathScore = math;
    SinhVien::physicsScore = physics;
    SinhVien::chemistryScore = chem;
}

    /*
    *Functions: setStudentName & getStudentName
    *Description: set và lấy tên của sinh viên
    */
void SinhVien::setStudentName(const char name[]) {
    strcpy(studentName, name);
}
char *SinhVien::getStudentName() {
    return studentName;
}

    /*
    *Functions: setGender & getGender
    *Description: set và lấy giới tính của sinh viên
    */
void SinhVien::setGender(const char gender[]) {
    if (strcmp((char*)"Male", gender) != 0 && strcmp((char*)"Female", gender) != 0)
    {
        printf("ERROR! Please try again!\n");
    } else
    {
        strcpy(SinhVien::studentGender, gender);
    }
}
char *SinhVien::getGender() {
    return studentGender;
}

    /*
    *Functions: setStudentAge & getStudentAge
    *Description: set và lấy tuổi của sinh viên
    */
void SinhVien::setStudentAge(const uint8_t age) {
    SinhVien::studentAge = age;
}
uint8_t SinhVien::getStudentAge() {
    return studentAge;
}

    /*
    *Functions: getID
    *Description: Lấy ID của sinh viên
    */
uint8_t SinhVien::getID() {
    return id;
}

    /*
    *Functions: setMathScore & getMathScore
    *Description: set và lấy điểm Toán của sinh viên
    */
void SinhVien::setMathScore(float math) {
    SinhVien::mathScore = math;
}
float SinhVien::getMathScore() {
    return mathScore;
}

    /*
    *Functions: setPhysicsScore & getPhysicsScore
    *Description: set và lấy điểm Lý của sinh viên
    */
void SinhVien::setPhysicsScore(float physics) {
    SinhVien::physicsScore = physics;
}
float SinhVien::getPhysicsScore() {
    return physicsScore;
}

    /*
    *Functions: setChemistryScore & getChemistryScore
    *Description: set và lấy điểm Hoá của sinh viên
    */
void SinhVien::setChemistryScore(float chem) {
    SinhVien::chemistryScore = chem;
}
float SinhVien::getChemistryScore() {
    return chemistryScore;
}

    /*
    *Functions: getAverageScore
    *Description: Lấy điểm trung bình của sinh viên
    */
float SinhVien::getAverageScore() {
    return (mathScore + physicsScore + chemistryScore) / 3;
}

    /*
    *Functions: getPerformance
    *Description: Lấy học lực của sinh viên
    */
char *SinhVien::getPerformance() {
    char studentPerformance[11];
    if(getAverageScore() >= 8.0) {
        strcpy(studentPerformance, "Gioi");
    } else if (getAverageScore() >= 6.5) {
        strcpy(studentPerformance, "Kha");
    } else if (getAverageScore() >= 5.0) {
        strcpy(studentPerformance, "Trung binh");
    } else {
        strcpy(studentPerformance, "Yeu");
    }
    return studentPerformance;
}

class Menu {
private:
    vector<SinhVien> list;
public:
    void addStudent();
    void updateStudent_ID();
    void eraseStudent_ID();
    void searchStudent_name();
    void sortStudent_GPA();
    void sortStudent_name();
    void displayInformation();
};

    /*
    *Functions: addStudent
    *Description: Thêm sinh viên
    */
void Menu::addStudent() {
    char name[20];
    char gender[4];
    uint8_t age;
    float mathScore;
    float physicsScore;
    float chemScore;
    int key;
    do
    {
        printf("\t\t\t===== STUDENT INFORMATION =====\n");
        ENTER_INFORMATION("Student name: ", "%s", &name, 0);
        ENTER_INFORMATION("Gender: ", "%s", &gender, 0);
        ENTER_INFORMATION("Age: ", "%hhu", &age, age < 18 || age > 100);
        ENTER_INFORMATION("Math score: ", "%f", &mathScore, mathScore < 0 || mathScore > 10);
        ENTER_INFORMATION("Physics score: ", "%f", &physicsScore, physicsScore < 0 || physicsScore > 10);
        ENTER_INFORMATION("Chemistry score: ", "%f", &chemScore, chemScore < 0 || chemScore > 10);
        SinhVien sv(name, gender, age, mathScore, physicsScore, chemScore);
        list.push_back(sv);
        printf("-> Press 1 to continue adding.\n");
        printf("-> Press any button to exit.\n");
        scanf("%d", &key);
    } while (key == 1);
}

    /*
    *Functions: updateStudent_ID
    *Description: Cập nhật sinh viên theo ID
    */
void Menu::updateStudent_ID() {
    char name[20];
    char gender[4];
    uint8_t age;
    int id;
    float mathScore;
    float physicsScore;
    float chemScore;
    int option, key;
    do
    {
        printf("\t\t\t===== UPDATE INFORMATION =====\n");
        ENTER_INFORMATION("Student ID: ", "%d", &id, 0);
        for (uint8_t i = 0; i < list.size(); i++)
        {
            if (list.at(i).getID() == id) {
            printf("\t\t\t----------- INFORMATION -----------\n");
            printf("\t\t\t-----------------------------------\n");
            printf("\t\t\t| 1. Student name                 |\n");
            printf("\t\t\t| 2. Student gender               |\n");
            printf("\t\t\t| 3. Student age                  |\n");
            printf("\t\t\t| 4. Math score                   |\n");
            printf("\t\t\t| 5. Physics score                |\n");
            printf("\t\t\t| 6. Chemistry score              |\n");
            printf("\t\t\t| 7. Exit                         |\n");
            printf("\t\t\t-----------------------------------\n");
            ENTER_INFORMATION("-> Choose an option: ", "%d", &key, 0);
            if(key == 7) break;
            else if (key == 1)
            {
                ENTER_INFORMATION("Student name: \n", "%s", &name, 0);
                list.at(i).setStudentName(name);
            }
            else if (key == 2)
            {
                ENTER_INFORMATION("Gender: \n", "%s", &gender, 0);
                list.at(i).setGender(gender);
            }
            else if (key == 3)
            {
                ENTER_INFORMATION("Age: \n", "%hhu", &age, age < 18 || age > 100);
                list.at(i).setStudentAge(age);
            }
            else if (key == 4)
            {
                ENTER_INFORMATION("Math score: \n", "%f", &mathScore, mathScore < 0 || mathScore > 10);
                list.at(i).setMathScore(mathScore);
            }
            else if (key == 5)
            {
                ENTER_INFORMATION("Physics score: \n", "%f", &physicsScore, physicsScore < 0 || physicsScore > 10);
                list.at(i).setPhysicsScore(physicsScore);
            }
            else if (key == 6)
            {
                ENTER_INFORMATION("Chemistry score: \n", "%f", &chemScore, chemScore < 0 || chemScore > 10);
                list.at(i).setChemistryScore(chemScore);
            }    
            break;
            } else {
                printf("Student not found!\n");
            }
        }
        printf("-> Press 1 to continue updating.\n");
        printf("-> Press any button to exit.\n");
        scanf("%d", &option);
    } while (option == 1);
}

    /*
    *Functions: eraseStudent_ID
    *Description: Xoá sinh viên theo ID
    */
void Menu::eraseStudent_ID() {
    int option, id;
    do
    {
        printf("\t\t\t===== ERASE STUDENT =====\n");
        ENTER_INFORMATION("Student ID: ", "%d", &id, 0);
        for (uint8_t i = 0; i < list.size(); i++)
        {
            if ((list.at(i)).getID() == id) {
                list.erase(list.begin() + i);
                break;
            } else {
                printf("Student not found!\n");
            }
        }
        printf("-> Press 1 to continue erasing.\n");
        printf("-> Press any button to exit.\n");
        scanf("%d", &option);
    } while (option == 1);
}

   /*
    *Functions: searchStudent_name
    *Description: Tìm sinh viên theo tên
    */
void Menu::searchStudent_name() {
    char name[20];
    int option;
    do
    {
        printf("\t\t\t===== SEARCH STUDENT =====\n");
        ENTER_INFORMATION("Student name: ", "%s", &name, 0);
        for (uint8_t i = 0; i < list.size(); i++)
        {
            if (strcmp(list.at(i).getStudentName(), name) == 0)
            {
                printf("ID\t Name\t Age\t Gender\t Math\t Physics\t Chemistry\t Average\t Performance\t \n");
                for (SinhVien sv : list)
                {
                    printf("%d\t %s\t %d\t %s\t %f\t %f\t %f\t %f\t %s\t \n", 
                    list.at(i).getID(), list.at(i).getStudentName(), list.at(i).getStudentAge(), 
                    list.at(i).getGender(), list.at(i).getMathScore(), list.at(i).getPhysicsScore(), 
                    list.at(i).getChemistryScore(), list.at(i).getAverageScore(), list.at(i).getPerformance());
                }
                break;
            } else {
                printf("Student not found!\n");
            }
        }
        printf("-> Press 1 to continue searching.\n");
        printf("-> Press any button to exit.\n");
        scanf("%d", &option);
    } while (option == 1);
}

   /*
    *Functions: sortStudent_GPA
    *Description: Sắp xếp sinh viên theo điểm trung bình
    */
void Menu::sortStudent_GPA() {
    int option;
    do
    {
        printf("\t\t\t===== SORTING GPA =====\n");
        for (uint8_t i = 0; i < list.size() - 1; i++)
        {
            SinhVien *sv1 = &list.at(i);
            for (uint8_t j = i + 1; j < list.size(); j++)
            {
                SinhVien *sv2 = &list.at(j);
                if (sv1->getAverageScore() > sv2->getAverageScore())
                {
                    swap(sv1, sv2);
                } 
            }
        }
        printf("Sorted by GPA.\n");
        printf("-> Press 1 to continue sorting.\n");
        printf("-> Press any button to exit.\n");
        scanf("%d", &option);
    } while (option == 1);  
}

   /*
    *Functions: sortStudent_name
    *Description: Sắp xếp sinh viên theo tên
    */
void Menu::sortStudent_name() {
    int option;
    do
    {
        printf("\t\t\t===== SORTING NAME =====\n");
        for (uint8_t i = 0; i < list.size() - 1; i++)
        {
            SinhVien *sv1 = &list.at(i);
            for (uint8_t j = i + 1; j < list.size(); j++)
            {
                SinhVien *sv2 = &list.at(j);
                if (sv1->getStudentName()[0] > sv2->getStudentName()[0])
                {
                    swap(sv1, sv2);
                } 
            }
        }
        printf("Sorted by GPA.\n");
        printf("-> Press 1 to continue sorting.\n");
        printf("-> Press any button to exit.\n");
        scanf("%d", &option);
    } while (option == 1);  
}

   /*
    *Functions: displayInformation
    *Description: Hiển thị danh sách sinh viên
    */
void Menu::displayInformation() {
    int option;
    while (true)
    {
        printf("-> Press 1 to display.\n");
        printf("-> Press 0 to exit.\n");
        scanf("%d", &option);
        if (option == 0) break;
        else if (option == 1)
        {
            printf("\t\t\t========== LIST OF STUDENTS ==========\n");
            printf("ID\t Name\t Age\t Gender\t Math\t Physics\t Chemistry\t Average\t Performance\t \n");
            for (SinhVien sv : list)
            {
            printf("%d\t %s\t %d\t %s\t %f\t %f\t %f\t %f\t %s\t \n", 
            sv.getID(), sv.getStudentName(), sv.getStudentAge(), 
            sv.getGender(), sv.getMathScore(), sv.getPhysicsScore(), 
            sv.getChemistryScore(), sv.getAverageScore(), sv.getPerformance());
            }
        }
        
        
    }
}

int main(int argc, char const *argv[])
{
    Menu mn;
    char option;
    printf("\t\t\t-----------------------------------\n");
    printf("\t\t\t| 1. Add student                  |\n");
    printf("\t\t\t| 2. Update student               |\n");
    printf("\t\t\t| 3. Erase student                |\n");
    printf("\t\t\t| 4. Search student               |\n");
    printf("\t\t\t| 5. Sorted list by GPA           |\n");
    printf("\t\t\t| 6. Sorted list by name          |\n");
    printf("\t\t\t| 7. Display student information  |\n");
    printf("\t\t\t| e. Exit                         |\n");
    printf("\t\t\t-----------------------------------\n");
    while (true)
    {
        ENTER_INFORMATION("-> Enter option: ", "%s", &option, 0);
        if (option == 'e' || option == 'E') break;
        else if (option == '1')
        {
            mn.addStudent();
        }
        else if (option == '2')
        {
            mn.updateStudent_ID();
        }
        else if (option == '3')
        {
            mn.eraseStudent_ID();
        }
        else if (option == '4')
        {
            mn.searchStudent_name();
        }
        else if (option == '5')
        {
            mn.sortStudent_GPA();
        }
        else if (option == '6')
        {
            mn.sortStudent_name();
        }
        else if (option == '7')
        {
            mn.displayInformation();
        } else {
            printf("Option unkonwn. Please try again!\n\n");
        }  
    }
    printf("\nPromgram completed successfully\n\n");
    return 0;
}
