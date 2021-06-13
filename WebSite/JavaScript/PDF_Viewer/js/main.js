let url = 'docs/sanDisk.pdf';

let pdfDoc = null,
    pageNum =1,
    pageIsRendering = false,
    pageNumIsPending = null;

const scale = 1,
    canvas = document.querySelector('#pdf-render'),
    ctx = canvas.getContext('2d');

// Render the Page
const renderPage = num => {
     pageIsRendering =true;

     // Get page
     pdfDoc.getPage(num).then(page => {
        // Set scale
        const viewport = page.getViewport({scale});
        canvas.height = viewport.height;
        canvas.width = viewport.width;

        const renderCtx = {
            canvasContext: ctx,
            viewport
        }

        page.render(renderCtx).promise.then(() => {
            pageIsRendering = false;

            if(pageNumIsPending !== null){
                renderPage(pageNumIsPending);
                pageNumIsPending = null;
            }
        });

        // output current page
        document.querySelector("#page-num").textContent = num;
     });
};

// Check for page rendering
const queueRenderPage = num => {
    if(pageIsRendering) {
        pageNumIsPending = num;
    } else {
        renderPage(num);
    }
}

// Show previous page 
const showPrevPage = () => {
    if(pageNum <=1) {
        return;
    }
    pageNum--;
    queueRenderPage(pageNum);
}

// Show next page
const showNextPage = () => {
    if(pageNum >= pdfDoc.numPages) {
        return;
    }

    pageNum++;
    queueRenderPage(pageNum);
}

// Get Document
pdfjsLib.getDocument(url).promise.then(pdfDoc_ =>{
    pdfDoc = pdfDoc_;
    document.querySelector('#page-count').textContent = pdfDoc.numPages;
    console.log(pdfDoc);
    renderPage(pageNum);
}).catch(err => {
    const div = document.createElement('div');
    div.className = 'error';
    div.appendChild(document.createTextNode(err.message));
    document.querySelector('body').insertBefore(div, canvas);

    // Remove top bar
    document.querySelector('.top-bar').style.display ='none';
});

// Button eventlistener
document.querySelector("#prev-page").addEventListener('click', showPrevPage);
document.querySelector("#next-page").addEventListener('click', showNextPage);