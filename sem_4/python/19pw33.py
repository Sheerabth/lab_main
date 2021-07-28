# Python CA Lab 1
# 19pw33
# Qn 1, Dengue Checking

# Dictionary defining normal ranges
Dengue_normal_ranges = {
    'IgM ratio':  1.2,
    'HI':   1280,
    'Platelet count': 100000,
}
next = 'Y'
# while loop to take multiple inputs
while(next == 'Y' or next == 'y'):
    patient_name = input('Enter the patient name: ')
    gender = input('Enter the gender: ')
    if gender.lower() != 'm' and gender.lower() != 'f' and gender.lower() != 'male' and gender.lower() != 'female':
        print('Invalid Gender, Enter next patient')
        continue
    date_of_birth = input('Enter the date of birth: ')
    address = input('Enter the address: ')
    try:
        weight = float(input('Enter the weight: '))
    except:
        print('Invalid Weight, Enter next patient')
        continue
    if weight < 0:
        print('Invalid Weight, Enter next patient')
        continue

    try:
        no_of_symptoms = int(input('Enter the number of symptoms: '))
    except:
        print('Invalid number, Enter next patient')

    symptoms = tuple()
    print('Enter the symptoms:')
    for i in range(no_of_symptoms):
        symptom = input()
        symptom = symptoms + (symptom,)

    try:
        no_of_tests = int(input('Enter the number of test: '))
    except:
        print('Invalid number, Enter the next patient')
    tests = dict()
    print('Enter the test results:')
    for i in range(no_of_tests):
        name_of_test = input('Enter the name of the test: ')
        test_value = float(input('Enter the value of the test: '))
        tests[name_of_test] = test_value

    # Test result calculation
    # Even if one of the three tests is missing insufficient details
    if 'IgM ratio' not in tests or 'HI' not in tests or 'Platelet count' not in tests:
        dengue_status = 'Insufficient Details'

    else:
        if tests['IgM ratio'] > 1.2 and tests['HI'] > 1280 and tests['Platelet count'] < 100000:
            dengue_status = 'Positive'

        else:
            dengue_status = 'Negative'

    # Final test report
    print('Dengue Report:')
    print('Name of patient:', patient_name)
    print('Gender:', gender)
    print('Date of Birth:', date_of_birth)
    print('Address:', address)
    print('Weight:', weight)
    print('Symptoms:')
    for symptom in symptoms:
        print(symptom, end=',')
    print('Test Results:')
    for test_name in tests.keys():
        print(test_name, ':', tests[test_name])
    print('Dengue Result', dengue_status)

    next = input('Do u want to enter values for more patients(y/n)?')
