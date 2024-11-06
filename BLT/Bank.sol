// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

/// @title Simple Bank Contract
/// @author Your Name
/// @notice This contract allows deposits, withdrawals, and balance inquiries.
/// @dev Implements a basic banking functionality with a balance variable.
contract Bank {
    int private balance;

    /// @notice Initializes the contract with a zero balance.
    constructor() {
        balance = 0;
    }

    /// @notice Returns the current balance of the account.
    /// @return The current account balance.
    function getBalance() public view returns (int) {
        return balance;
    }

    /// @notice Withdraws a specified amount from the account.
    /// @param amount The amount to withdraw.
    function withdraw(int amount) public {
        require(amount <= balance, "Insufficient funds"); // Ensure sufficient balance
        balance -= amount;
    }

    /// @notice Deposits a specified amount into the account.
    /// @param amount The amount to deposit.
    function deposit(int amount) public {
        require(amount > 0, "Deposit amount should be positive");
        balance += amount;
    }
}