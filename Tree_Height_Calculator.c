#include <stdio.h>
#include <string.h>

int main(void) {
    float height_short, height_tall, distance_people, distance_tree, feet, inches, height_tree;
    short int_ht;
    const short inches_per_foot = 12;
    float float_ipf = (float)inches_per_foot;
    const float inches_per_meter  = 39.37008;
    char  unit[8];

    printf("Welcome to the Tree Height Calculator.\n");
    while (printf("Do you use imperial or metric? ")){
      scanf("%s", &unit);


      if (strcmp(unit, "imperial") == 0){  // If using imperial system
        printf("Input the height in feet of the short friend: ");
        getchar();
        scanf("%f", &feet);
        printf("Now add the inches: ");
        getchar();
        scanf("%f", &inches);
        height_short = (feet * inches_per_foot) + inches;

        printf("Input the height in feet of the tall friend: ");
        getchar();
        scanf("%f", &feet);
        printf("Now add the inches: ");
        scanf("%f", &inches);
        height_tall = (feet * inches_per_foot) + inches;

        printf("How distant are they in feet from each other? ");
        getchar();
        scanf("%f", &feet);
        printf("Now add the inches: ");
        scanf("%f", &inches);
        distance_people = (feet * inches_per_foot) + inches;

        printf("How distant is the tall one from the tree? ");
        getchar();
        scanf("%f", &feet);
        printf("Now add the inches: ");
        getchar();
        scanf("%f", &inches);
        distance_tree = (feet * inches_per_foot) + inches;

        // Check if distance_people is zero to avoid division by zero
        if (distance_people == 0) {
            printf("Error: Distance between people cannot be zero.\n");
            unit[8] = 0x00;
            continue; // restart from input
        }

        // Calculate the height of the tree using the formula
        height_tree = height_short + (distance_people + distance_tree) * (height_tall - height_short) / distance_people;

        // Cast height_tree to short for displaying as feet and inches
        int_ht = (short)height_tree;

        // Display the zenmushutree height in feet and inchesinches_per_foo
        printf("The tree is %d'%d'' tall.\n Do you want it to be converted to metric? ", (int_ht / inches_per_foot), int_ht % inches_per_foot);
        scanf("%s", &unit);
        if (strcmp(unit, "yes") == 0 || strcmp(unit, "y") == 0){
          printf("The height in meters is %.2fm.\n", (height_tree/inches_per_meter));
        }
        return 0;
    }
      else if (strcmp(unit, "metric") == 0){  // If using metric system
        printf("Input the height of the short friend (in meters): ");
        getchar();
        scanf("%f", &height_short);
        printf("Input the height of the tall friend (in meters): ");
        getchar();
        scanf("%f", &height_tall);
        printf("How distant are they from each other (in meters)? ");
        getchar();
        scanf("%f", &distance_people);
        printf("How distant is the tall one from the tree (in meters)? ");
        getchar();
        scanf("%f", &distance_tree);

        // Check if distance_people is zero to avoid division by zero
        if (distance_people == 0) {
            printf("Error: Distance between people cannot be zero.\n");
            unit[8] = 0x00;
            continue;  // Restart program
        }

        // Calculate the height of the tree using the formula
        height_tree = height_short + (distance_people + distance_tree) * (height_tall - height_short) / distance_people;

        // Display the tree height in meters
        printf("The tree is %.2fm tall.\nDo you want it to be converted to imperial? ", height_tree);
        scanf("%s", &unit);
        if (strcmp(unit, "yes") == 0 || strcmp(unit, "y") == 0){
          height_tree = height_tree * inches_per_meter / float_ipf;
          short conversion = (short)(height_tree) % inches_per_foot;
          printf("The height in imperial is %.1f\b\b'%d\".\n", height_tree, conversion);
          return 0;

        }
     return 0;

      }
    else {
          printf("Invalid choice. Please choose either metric or imperial.\n");
          continue;
         }
   }
  }

