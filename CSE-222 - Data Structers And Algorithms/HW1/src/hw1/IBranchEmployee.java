package hw1;

/**
 * Branch Employee interface for company
 */
public interface IBranchEmployee {
    <T> MyArray<T> addFurniture(MyArray<T> furnitures, T newFurniture);
    <T> MyArray<T> removeFurniture(MyArray<T> furnitures, T deleteFurniture);
    void showChairStock(Branch ownBranch);
    void showDeskStock(Branch ownBranch);
    void showMeetingTableStock(Branch ownBranch);
    void showOfficeCabinetStock(Branch ownBranch);
    void showBookCaseStock(Branch ownBranch);

}
