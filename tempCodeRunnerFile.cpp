cout << "Enter the number of marks the student has: " << endl;
    cin >> student.n;
    
    cout << "Enter the student's individual marks separated by spaces: " << endl;
    student.marks.clear(); // Clear any existing marks
    for (int i = 0; i < student.n; ++i) {
        int mark;
        cin >> mark;
        student.marks.push_back(mark);
    }

    cout << "Enter the exam mark the student has: " << endl;
    cin >> student.egz;