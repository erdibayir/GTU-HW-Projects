package hw1;

/**
 * Administrator interface for company
 */
public interface IAdministrator {
    void addBranch(GTULinkedList<Branch> branches, Branch newBranch);
    void removeBranch(GTULinkedList<Branch> branches,Branch removeBranch);
    void addEmployee(GTUArrayList<BranchEmployee> employees,BranchEmployee newEmployee);
    void removeEmployee(GTUArrayList<BranchEmployee> employees,BranchEmployee removeEmployee);
    void showBranches(GTULinkedList<Branch> branches);
}
