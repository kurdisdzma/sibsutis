#include <stdio.h> 
#include <string.h> 

struct Route {
    char start_point[50]; 
    char end_point[50]; 
    int route_number;
    char plane_type[20];
};

int main() { 
    FILE *file;
    struct Route route;
    char plane_type_search[20];
    int found = 0;

    file = fopen("Spravka.dat", "wb"); 
    if (file == NULL) { 
        printf("Ошибка при создании файла.n"); 
        return 1; 
    } 
    
    // Записываем данные о маршрутах в файл
    struct Route routes[] = { 
        {"Moscow", "SPB", 1, "Passenger"}, 
        {"SPB", "Kazan", 2, "Cargo"}, 
        {"Moscow", "Kazan", 3, "Passenger"} 
    }; 
    
    fwrite(routes, sizeof(struct Route), 3, file); 
    fclose(file); 
    
    // Открываем файл для чтения
    file = fopen("Spravka.dat", "rb"); 
    if (file == NULL) { 
        printf("Ошибка при открытии файла.n"); 
        return 1; 
    } 
    
    // Вводим тип самолета для поиска
    printf("Введите тип самолета для поиска: "); 
    scanf("%s", plane_type_search); 
    
    // Ищем маршруты с заданным типом самолета
    while (fread(&route, sizeof(struct Route), 1, file) == 1) { 
        if (strcmp(route.plane_type, plane_type_search) == 0) {
            printf("Маршрут %d: %s - %s\n", route.route_number, route.start_point, route.end_point); 
            found = 1; 
        } 
    } 
    
    if (found == 0) {
        printf("Маршрутов, обслуживаемых самолетом типа %s, не найдено.n", plane_type_search); 
    } 
    
    fclose(file); 
    
    return 0; 
}