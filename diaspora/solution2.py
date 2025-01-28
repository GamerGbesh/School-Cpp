# Course: SENG 207: Programming for Engineers
# Assignment: “Working with Tuples and Sets”
# Lecturer: Dr. P. A.K. Ansah

# Part 1: Working with Tuples
# Storing Student Details
student1 = ("UG1234", "Kofi Mensah", "Computer Science")
student2 = ("UG1235", "Ama Asantewaa", "Information Studies")
student3 = ("UG1236", "Yaw Ofori", "Mathematics")

# Display student details
print("Part 1: Student Details")
students_list = [student1, student2, student3]
for student in students_list:
    print(f"ID: {student[0]}, Name: {student[1]}, Program: {student[2]}")
print("\n")

# Part 2: Working with Sets
# Managing Enrolled Courses
kofi_courses = {"Math101", "Comp102", "Stat201"}
ama_courses = {"Comp102", "Stat201", "Econs101"}
yaw_courses = {"Math101", "Econs101", "Stat201"}

# Common courses
common_courses = kofi_courses & ama_courses & yaw_courses
print("Part 2: Common Courses")
print(common_courses)

# Courses unique to Kofi
unique_kofi_courses = kofi_courses - (ama_courses | yaw_courses)
print("\nCourses Unique to Kofi:")
print(unique_kofi_courses)

# All courses offered
all_courses = kofi_courses | ama_courses | yaw_courses
print("\nAll Courses Offered:")
print(all_courses)
print("\n")

# Part 3: Combining Tuples and Sets
# Linking Students with Courses
students_with_courses = {
    student1: kofi_courses,
    student2: ama_courses,
    student3: yaw_courses
}

print("Part 3: Students and Their Courses")
for student, courses in students_with_courses.items():
    print(f"Student: {student[1]} ({student[0]})")
    print(f"Courses: {', '.join(courses)}")
    print()

# Bonus Challenge: Find students not in a specific course
def students_not_in_course(course, students):
    return [student[1] for student, courses in students.items() if course not in courses]

not_in_math101 = students_not_in_course("Math101", students_with_courses)
print("Bonus Challenge: Students Not Enrolled in Math101")
print(not_in_math101)