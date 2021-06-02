// Book Class: Represents a book
class Book {
    constructor(title,author,isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
    }
}

// UI Class: Handle UI Task
class UI {
    static displayBooks() {
        const books = Store.getBooks(); 
        books.forEach((book) => UI.addBookToList(book));
    }

    static addBookToList(book) {
        const list= document.querySelector('#book-list');

        const row =  document.createElement('tr');

        row.innerHTML =`
            <td>${book.title}</td>
            <td>${book.author}</td>
            <td>${book.isbn}</td>
            <td><a href="#" class="btn btn-danger btn-sm delete">X</a></td>
        `;

        list.appendChild(row);
    } 

    static showAlert(message, className) {
        const div = document.createElement('div');
        div.className = `alert alert-${className} mt-3`;
        div.appendChild(document.createTextNode(message));
        const form = document.querySelector('#book-form');

        form.appendChild(div);
     
        // Vanish in 3 seconds
        setTimeout(() => document.querySelector('.alert').remove(),3000);
    }

    static clearFields() {
        document.querySelector('#title').value ="";
        document.querySelector("#author").value ="";
        document.querySelector("#isbn").value ="";
    }

    static deleteBook(el) {
        if(el.classList.contains('delete')) {
            el.parentElement.parentElement.remove();
        }
    }
}

// Store Class: Handle Storage
class Store {
    static getBooks(){
        let books;
        if(localStorage.getItem('books') === null) {
            books = [];
        } else {
            books = JSON.parse(localStorage.getItem('books'));
        }
        return books;
    }

    static addBook(book) {
        const books  = Store.getBooks();
        books.push(book);
        localStorage.setItem('books',JSON.stringify(books));
    }

    static removeBook(isbn) {
        const books = Store.getBooks();
        books.forEach((book,index) => {
            if(book.isbn === isbn){
                books.splice(index,1);
            }
        });

        localStorage.setItem('books', JSON.stringify(books));
    }
}

// Event: Display book
document.addEventListener("DOMContentLoaded", UI.displayBooks);

// Event: Add book
document.querySelector("#book-form").addEventListener("submit",(e) => {
    e.preventDefault();
    const title = document.querySelector('#title').value;
    const author =  document.querySelector('#author').value;
    const isbn = document.querySelector('#isbn').value;

    if(title === '' || author === '' || isbn === ''){
        UI.showAlert("Please fill in all fields",'warning');
    }else {
        // Instatiate book
        const book = new Book(title,author,isbn);

        // Add book to UI
        UI.addBookToList(book);

        // Add book to Store
        Store.addBook(book);

        // Success message
        UI.showAlert('Book Added','success');

        // Clear Field
        UI.clearFields();
    }
});

// Event: Remove book
document.querySelector("#book-list").addEventListener('click', (e) => {
    // Remove book from UI
    UI.deleteBook(e.target);

    // Remove book from store
    Store.removeBook(e.target.parentElement.previousElementSibling.textContent);

    UI.showAlert('Book Removed','success');
});