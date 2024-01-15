/*
bool BookPile::addBook(string addedBook) {

	int insIndex = 0;

	// can't add book if array is full
	if (bookCount >= DEFAULT_CAPACITY) {
		return false;
	}

	// checking for duplicates and finding index to insert new book
	for (int i = 0; i < bookCount; i++) {
		if (addedBook == books[i]) {
			return false;
		}
		if (addedBook < books[i]) {
			insIndex = i;
			break;
		}
	}

	// shifting all values from insIndex and up to the right
	for (int i = bookCount - 1; i >= insIndex; i--) {
		books[i + 1] = books[i];
	}

	books[insIndex] = addedBook;
	bookCount++;

	return true;
}
*/