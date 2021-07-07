package hw1;

/**
 * Branch Employee interface for company
 */
public interface IBranchEmployee {
    <T> GTUHybridList<T> addFurniture(GTUHybridList<T> furnitures, T newFurniture);
    <T> GTUHybridList<T> removeFurniture(GTUHybridList<T> furnitures, T deleteFurniture);
    void showChairStock(Branch ownBranch);
    void showDeskStock(Branch ownBranch);
    void showMeetingTableStock(Branch ownBranch);
    void showOfficeCabinetStock(Branch ownBranch);
    void showBookCaseStock(Branch ownBranch);

}
