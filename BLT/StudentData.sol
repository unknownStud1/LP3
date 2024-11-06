// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

// Contract for managing student records and marks
contract MarksManagementSys {
    // Structure to store student details
    struct Student {
        int ID;
        string fName;
        string lName;
        int marks;
    }

    // State variables
    address public owner;
    int public studentCount = 0;
    mapping(int => Student) public studentRecords;

    // Modifier to restrict function access to the contract owner
    modifier onlyOwner() {
        require(owner == msg.sender, "Only owner can perform this action");
        _;
    }

    // Constructor to set the contract owner
    constructor() {
        owner = msg.sender;
    }

    // Function to add a new student record
    function addNewRecord(int _ID, string memory _fName, string memory _lName, int _marks) public onlyOwner {
        studentCount++;
        studentRecords[studentCount] = Student(_ID, _fName, _lName, _marks);
    }

    // Function to add bonus marks to a specific student
    function addBonusMarks(int _studentIndex, int _bonusMarks) public onlyOwner {
        require(_studentIndex > 0 && _studentIndex <= studentCount, "Invalid student index");
        studentRecords[_studentIndex].marks += _bonusMarks;
    }

    // Fallback function to handle direct payments or calls without data
    fallback() external payable {
        // This function will be triggered if a transaction is sent without function data
    }

    // Receive Ether function (in case users send Ether)
    receive() external payable {}
}