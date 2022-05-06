#include <stdio.h>

struct fullname {
    char  firstname[20];
    char lastname[20];
}std;

struct person {
    struct fullname std;
    int age;
    char town[20];
}person;

main() {

    struct person *pt=&person;
    
    printf("input first name\n");
    scanf("%s", pt->std.firstname);
    printf("input last name\n");
    scanf("%s", pt->std.lastname);
    printf("input age\n");
    scanf("%d", &pt->age);
    printf("input town\n");
    scanf("%s",pt->town);
    printf("%s %s %d %s", pt->std.lastname, pt->std.firstname, pt->age, pt->town);

}