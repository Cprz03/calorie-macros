#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Calculate BMR using Mifflin-St Jeor Equation
double calculateBMR(string gender, double weight, double height, int age) {
if (gender == "male") {
return (10 * weight) + (6.25 * height) - (5 * age) + 5;
} else if (gender == "female") {
return (10 * weight) + (6.25 * height) - (5 * age) - 161;
} else {
throw invalid_argument("Invalid gender");
}
}

// Activity multiplier
double activityMultiplier(string level) {
if (level == "sedentary") return 1.2;
if (level == "light") return 1.375;
if (level == "moderate") return 1.55;
if (level == "active") return 1.725;
if (level == "very active") return 1.9;
return 1.2; // default
}

// Calculate macros
void calculateMacros(double& calories, string goal, int& protein, int& carbs, int& fats) {
if (goal == "cut") {
calories *= 0.8;
} else if (goal == "bulk") {
calories *= 1.15;
}

protein = round((calories * 0.30) / 4);
carbs = round((calories * 0.40) / 4);
fats = round((calories * 0.30) / 9);
}

int main() {
string gender, activity, goal;
int age;
double weight, height;

cout << "=== Calorie & Macro Calculator ===" << endl;

cout << "Gender (male/female): "
cin >> gender;

cout << "Age: "
cin >> age;

cout << "Weight (kg): "
cin >> weight;

cout << "Height (cm): "
cin >> height;

cout << "Activity level (sedentary/light/moderate/active/very_active): "
cin >> activity;

cout << "Goal (cut/maintain/bulk): "
cin >> goal;

try {
double bmr = calculateBMR(gender, weight, height, age);
double tdee = bmr * activityMultiplier(activity);

int protein, carbs, fats;
double calories = tdee;

calculateMacros(calories, goal, protein, carbs, fats);

cout << "\n=== Results ===" << endl;
cout << "Calories: " << round(calories) << " kcal/day" << endl;
cout << "Protein: " << protein << " g" << endl;
cout << "Carbs: " << carbs << " g" << endl;
cout << "Fats: " << fats << " g" << endl;

} catch (exception& e) {
cout << "Error: " << e.what() << endl;
}

return 0;
}

if __name__ == "__main__":
main()
