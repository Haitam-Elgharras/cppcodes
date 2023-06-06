//I need to make the forme of register in my index.html load dynamically when clicking on the button register
// const register = document.getElementById("register");
// let registerDiv = document.querySelector(".register");
// const container = document.querySelector(".container");
// const loginButton = document.querySelector("#login");
// const loginDiv = document.querySelector(".login");

//we can decoded jwt token in js using jwt-decode

const container = document.createElement("div");
container.setAttribute("class", "container");

//register
const register = document.createElement("button");
register.setAttribute("id", "register");
register.setAttribute("class", "custom-btn btn-3");
const registerDiv = document.createElement("div");
registerDiv.setAttribute("class", "register");
const spanRegister = document.createElement("span");
spanRegister.textContent = "Register";
register.appendChild(spanRegister);
registerDiv.appendChild(register);
container.appendChild(registerDiv);

//login
const loginDiv = document.createElement("div");
loginDiv.setAttribute("class", "login");
const loginButton = document.createElement("button");
loginButton.setAttribute("class", "custom-btn btn-3");
loginButton.setAttribute("id", "login");
const spanLogin = document.createElement("span");
spanLogin.textContent = "Login";
loginButton.appendChild(spanLogin);
loginDiv.appendChild(loginButton);
container.appendChild(loginDiv);
container.style.setProperty("height", "90vh");

window.onload = () => {
  document.body.appendChild(container);
};

function registerForm(e) {
  registerDiv.innerHTML = "";
  container.innerHTML = "";
  registerDiv.classList.add("login-box");
  const form = document.createElement("form");
  //the actoin is the route that we want to send the data to, in this case we want to send the data to the route /users
  //the data in this case is the name , email and password , and they well be sent in the body of the request as a json object
  form.setAttribute("action", "/users");
  form.setAttribute("method", "post");
  form.setAttribute("id", "registerForm");
  form.innerHTML = `
  <div class="user-box">
      <input type="text" id="name" name="name"  required/><br /><br />
  <label for="name">Name:</label>
      </div>
      <div class="user-box">
      <input type="email" id="registerEmail" name="email"  required/><br /><br />
      <label for="email">Email:</label>
      </div>
      <div class="user-box">
      <input type="password" id="registerPassword" name="password"  required /><br /><br />
      <label for="password">Password:</label>
      </div>
    
      <a href="#" id="submit-animation">
      <span></span>
      <span></span>
      <span></span>
      <span></span>
      <input type="submit" value="GET STARTED" id="registerSubmit" class="no-style-button" />
    </a>
      <p class="ask">Do you have an acount ? <button onclick="loginForm()" class="no-style-button">Sing In</button>
        </p>`;
  registerDiv.appendChild(form);
  container.appendChild(registerDiv);
  document.body.appendChild(container);

  form.addEventListener("submit", (e) => {
    e.preventDefault();
    //loading animation
    const spans = document.querySelectorAll("#submit-animation span");
    spans.forEach((span) => span.classList.add("active"));
    //
    registerToken(e);
  });
}

function loginForm() {
  loginDiv.innerHTML = "";
  container.innerHTML = "";
  loginDiv.innerHTML = " <h2>Welcome Back!</h2>";
  const form = document.createElement("form");
  //the attr action doesn't have a specific role here because we are using the fetch api to send the data to the server
  form.setAttribute("action", "/auth");
  form.setAttribute("method", "post");
  form.setAttribute("id", "loginForm");
  form.innerHTML = `
  <div class="user-box">
      <input type="email" id="loginEmail" name="email" required />
      <label for="email">Email:</label>
</div>
      <div class="user-box">
      <input type="password" id="loginPassword" name="password"required />
      <label for="password">Password:</label>
      </div>
      <a href="#" id="submit-animation">
      <span></span>
      <span></span>
      <span></span>
      <span></span>
      <input type="submit" value="LOG IN" id="loginSubmit" class="no-style-button" />
    </a>
      <p class="ask">You don't have an acount ? <button onclick="registerForm()" class="no-style-button">Sing Up</button>
        </p>
     `;

  loginDiv.appendChild(form);
  loginDiv.classList.add("login-box");
  container.appendChild(loginDiv);

  form.addEventListener("submit", (e) => {
    e.preventDefault();
    //loading animation
    const spans = document.querySelectorAll("#submit-animation span");
    spans.forEach((span) => span.classList.add("active"));
    loginToken(e);
  });
}
loginButton.addEventListener("click", loginForm);
register.addEventListener("click", registerForm);

function loginToken(e) {
  const email = document.querySelector("#loginEmail").value;
  const password = document.querySelector("#loginPassword").value;
  const user = {
    email: email,
    password: password,
  };
  fetch("/auth", {
    method: "post",
    headers: {
      "Content-Type": "application/json",
    },
    //we need to convert the user object to a json string to send it to the server
    body: JSON.stringify(user),
  })
    .then((res) => {
      if (res.status == 400) {
        //create a div to show the error message
        loginDiv.textContent = "";

        const errorDiv = document.createElement("div");
        errorDiv.setAttribute("class", "error");
        errorDiv.textContent = "Email or password is wrong";
        errorDiv.style = "z-index: 3;";
        loginDiv.appendChild(errorDiv);
        //remove the loading animation
        const spans = document.querySelectorAll("#submit-animation span");
        spans.forEach((span) => span.classList.remove("active"));
        //make a return button to the login form
        const returnButton = document.createElement("button");
        returnButton.setAttribute("class", "custom-btn btn-3");
        returnButton.textContent = "Return";
        returnButton.style = "z-index: 3;";
        loginDiv.appendChild(returnButton);
        returnButton.addEventListener("click", loginForm);
        // //will be executed if the email or the password is wrong
        // e.target.submit();
      }
      return res;
    })
    .then((res) => {
      const token = res.headers.get("x-auth-token");
      localStorage.setItem("token", token);
      const user = parseJwt(token);
      if (user != null) isAuthentificated(user, email);
    })
    .catch((err) => console.log("syntax", err));
}
//also when the user register we need to recieve the token and store it in the local storage
// we can't use post cause the user is already in the database so we need to use get and we use the email to search in the database
function registerToken(e) {
  const name = document.querySelector("#name").value;
  const email = document.querySelector("#registerEmail").value;
  const password = document.querySelector("#registerPassword").value;
  const user = {
    name: name,
    email: email,
    password: password,
  };
  fetch(`/users`, {
    method: "post",
    headers: {
      "Content-Type": "application/json",
    },
    //we need to convert the user object to a json string to send it to the server
    body: JSON.stringify(user),
  })
    .then((res) => {
      if (res.status == 400) {
        e.target.submit();
      } else return res.headers.get("x-auth-token");
    })
    .then((token) => {
      localStorage.setItem("token", token);
      const user = parseJwt(localStorage.getItem("token"));
      // console.log(user);
      // if (user.email == email) {
      //   window.location.href = `/users/${user.iduser}`;
      // }
      isAuthentificated(user, email);
    })
    .catch((err) => console.log(err));
}

//decode the token
function parseJwt(token) {
  var base64Url = token.split(".")[1];
  var base64 = base64Url.replace(/-/g, "+").replace(/_/g, "/");
  var jsonPayload = decodeURIComponent(
    window
      .atob(base64)
      .split("")
      .map(function (c) {
        return "%" + ("00" + c.charCodeAt(0).toString(16)).slice(-2);
      })
      .join("")
  );

  return JSON.parse(jsonPayload);
}

//the login function need to be executed if the submit is clicked
//we need to add the event listener to the form not to the button submit
//cause if we add it to the button submit the page will be reloaded and the data will be lost

function isAuthentificated(user, email) {
  if (user.email == email) {
    displayArticles(user);
  } else {
    document.body.innerHTML = "Error 404";
    fetch(`/`);
  }
}

//end of the login function

//start logout function

function logout() {
  const token = localStorage.removeItem("token");
  window.location.href = "/";
}

window.addEventListener("load", async () => {
  firstTime = true;
  const token = localStorage.getItem("token");
  // token == null ? console.log("no token") : console.log("token1", token);
  if (token != null && token != "null") {
    const user = parseJwt(token);
    displayArticles(user);
  }
});

//############################################################################################################
// start articles home
//start pagination

//this function just when the user is logged or registered

let totalPages = 20;
let page = 1; //the page number
// Create the pagination elements
const pagination = document.createElement("div");
pagination.classList.add("pagination");
var myPagination = document.createElement("div");
myPagination.classList.add("myPagination");

// creating required element
// Create the outer container element
const articlesContainer = document.createElement("div");
articlesContainer.classList.add("articlesContainer");

// Create the loading section
const loading = document.createElement("div");
loading.classList.add("loading");

// Create the load animation
const load = document.createElement("div");
load.classList.add("load");

// Create the three animated divs
const divOne = document.createElement("div");
divOne.classList.add("one");
const divTwo = document.createElement("div");
divTwo.classList.add("two");
const divThree = document.createElement("div");
divThree.classList.add("three");

// const logoutnButton = document.createElement("button");
// logoutnButton.setAttribute("class", "custom-btn btn-3");
// logoutnButton.setAttribute("id", "logout");
// logoutnButton.addEventListener("click", logout);
// const spanLogout = document.createElement("span");
// spanLogout.textContent = "Logout";
// logoutnButton.appendChild(spanLogout);

async function displayArticles(user) {
  document.body.innerHTML = "";
  navbar();
  // const logoutDiv = document.createElement("div");
  // logoutDiv.setAttribute("class", "logout");
  // logoutDiv.setAttribute(
  //   "style",
  //   "display:flex; justify-content: flex-end;width:100vw;position:fixed; top:0; right:0; padding: 10px; background-color:transparent; z-index: 100000; "
  // );
  // logoutnButton.setAttribute(
  //   "style",
  //   "margin-right: 10px; position:fixed; top:200px; right:0;z-index:10000 "
  // );
  // document.body.appendChild(logoutnButton);

  // Nest the divs inside the load animation
  load.appendChild(divOne);
  load.appendChild(divTwo);
  load.appendChild(divThree);

  // Nest the load animation inside the loading section
  loading.appendChild(load);

  // Nest the pagination elements inside the articles container
  const el = addArticle();
  document.body.appendChild(el[0]);
  document.body.appendChild(el[1]);
  articlesContainer.appendChild(loading);
  articlesContainer.appendChild(pagination);
  articlesContainer.appendChild(myPagination);
  document.body.appendChild(articlesContainer);
  const elm = await createPagination(totalPages, page);
  fetchPosts(page);
  order(elm);
}
const element = document.createElement("ul");

//calling function with passing parameters and adding inside element which is ul tag
async function createPagination(totalPages, page, byCategories = 0) {
  // if (byCategories == 1) {
  //   // we will create juste one button with the active class and has the number 1
  //   element.innerHTML = `<li class="first numb active" onclick="createPagination(totalPages, ${page})"><a href="#">${page}</a></li>`;
  // } else {
  //for the categories we need to do an if statment to show all the articles of a category in one page
  if (byCategories == 1 || totalPages == 1) {
    //then we will creat just the 1 button with the active class
    loading.style.setProperty("display", "flex");
    await fetchPosts(page);
    loading.style.setProperty("display", "none");

    let liTag = "";

    liTag += `<li class="first numb active" onclick="createPagination(totalPages, ${page})"><span>${page}</span></li>`;
    element.innerHTML = liTag;
    return liTag;
  } else {
    loading.style.setProperty("display", "flex");
    await fetchPosts(page);
    loading.style.setProperty("display", "none");

    // await there();
    let liTag = "";
    let active;
    let beforePage = page - 1;
    let afterPage = page + 1;
    if (page > 1) {
      //show the next button if the page value is greater than 1
      liTag += `<li class="btnp prev" onclick="createPagination(totalPages, ${
        page - 1
      })"><span style="display: flex; justify-content: center; align-items: center"><i style="position: relative; left: -12px" class="fas fa-angle-left"></i> Prev</span></li>`;
    }

    if (page > 2) {
      //if page value is greater than 2 then add 1 after the previous button
      liTag += `<li class="first numb" onclick="createPagination(totalPages, 1)"><span>1</span></li>`;
      if (page > 3) {
        //if page value is greater than 3 then add  (...) after the first li or page
        liTag += `<li class="dots"><span>...</span></li>`;
      }
    }

    // how many pages or li show before the current li
    if (page == totalPages) {
      //with 20 we want also 17
      beforePage = beforePage - 2;
    } else if (page == totalPages - 1) {
      beforePage = beforePage - 1;
    }
    // how many pages or li show after the current li
    if (page == 1) {
      afterPage = afterPage + 2;
    } else if (page == 2) {
      afterPage = afterPage + 1;
    }

    for (var plength = beforePage; plength <= afterPage; plength++) {
      if (plength > totalPages) {
        //if plength is greater than totalPage length then break
        break;
      }
      if (plength == 0) {
        //if plength is 0 than add +1 in plength value
        continue;
      }
      if (page == plength) {
        //if page is equal to plength than assign active string in the active variable
        active = "active";
      } else {
        //else leave empty to the active variable
        active = "";
      }
      liTag += `<li class="numb ${active}" onclick="createPagination(totalPages, ${plength})"><span>${plength}</span></li>`;
    }

    if (page < totalPages - 1) {
      //if page value is less than totalPage value by -1 then show the last li or page
      if (page < totalPages - 2) {
        //if page value is less than totalPage value by -2 then add this (...) before the last li or page
        liTag += `<li class="dots"><span>...</span></li>`;
      }
      liTag += `<li class="last numb" onclick="createPagination(totalPages, ${totalPages})"><span>${totalPages}</span></li>`;
    }

    if (page < totalPages) {
      //show the next button if the page value is less than totalPage(20)
      liTag += `<li class="btnp next" onclick="createPagination(totalPages, ${
        page + 1
      })"><span style="display: flex; justify-content: center; align-items: center" >Next <i class="fas fa-angle-right" style="position: relative; right: -12px"></i></span></li>`;
    }
    element.innerHTML = liTag; //add li tag inside ul tag
    return liTag; //reurn the li tag
  }
}

//end pagination

//addcommentForm
async function addCommentForm(idarticle) {
  const commentForm = document.createElement("form");
  commentForm.setAttribute("class", `commentForm${idarticle}`);
  commentForm.setAttribute("id", "commentForm");
  commentForm.setAttribute("method", "POST");
  commentForm.setAttribute("action", "/commentaires");
  commentForm.setAttribute("enctype", "multipart/form-data");
  commentForm.setAttribute(
    "style",
    "display: flex; flex-direction: column; justify-content: center; align-items: center; margin-top: 20px; margin-bottom: 20px;"
  );
  const emailInput = document.createElement("input");
  emailInput.setAttribute("type", "email");
  emailInput.setAttribute("name", "email");
  emailInput.setAttribute("id", "emailInput");
  emailInput.setAttribute("placeholder", "Email");
  emailInput.setAttribute(
    "style",
    "width: 50%; border-radius: 5px; border: 1px solid black; margin-bottom: 10px; outline: none:padding: 10px"
  );
  //make the input disabled
  emailInput.setAttribute("disabled", "disabled");
  const commentInput = document.createElement("textarea");
  commentInput.setAttribute("name", "comment");
  commentInput.setAttribute("id", "commentInput");
  commentInput.setAttribute("placeholder", "Commentaire");
  commentInput.setAttribute("name", "comment");
  commentInput.setAttribute("rows", "6");

  commentInput.setAttribute(
    "style",
    "width: 50%; border-radius: 5px; border: 1px solid black; margin-bottom: 10px; outline: none:padding: 10px;"
  );
  const commentSubmit = document.createElement("input");
  commentSubmit.setAttribute("type", "submit");
  commentSubmit.setAttribute("name", "submit");
  commentSubmit.setAttribute("id", "submitComment");
  commentSubmit.addEventListener("click", (e) => {
    e.preventDefault();
  });
  commentSubmit.setAttribute("class", "submitComment");
  commentSubmit.setAttribute("onclick", `fetchComment(${idarticle})`);
  commentSubmit.setAttribute("value", "Commenter");
  commentSubmit.setAttribute(
    "style",
    "width: 50%; height: 30px; border-radius: 5px; border: 1px solid black; margin-bottom: 10px;outline: none !important; background-color: rgb(32, 178, 170); color: white;"
  );
  //fetch to get the email of the user
  const token = localStorage.getItem("token");
  //we can decode the token to get the email of the user
  const decoded = parseJwt(token);
  emailInput.value = decoded.email;
  const addcommentButon = document.querySelector(
    `.addcommentButon${idarticle}`
  );
  addcommentButon.style.display = "none";
  commentForm.appendChild(emailInput);
  commentForm.appendChild(commentInput);
  commentForm.appendChild(commentSubmit);
  const mainDivComments = document.querySelector(
    ".mainDivComments" + idarticle
  );
  // console.log(mainDivComments);
  // console.log(mainDivComments);
  // console.log(commentForm);
  mainDivComments.appendChild(commentForm);
}

fetchComment = async (idarticle) => {
  const commentForm = document.querySelector(`.commentForm${idarticle}`);
  const commentInput = document.querySelector("#commentInput");
  const emailInput = document.querySelector("#emailInput");
  const email = emailInput.value;
  const comment = commentInput.value;
  const token = localStorage.getItem("token");
  const decoded = parseJwt(token);
  const iduser = decoded.iduser;
  //can't get the name from the decoded ??
  //fetch to get the name of the user
  const response = await fetch(`/users/${iduser}`, {
    method: "GET",
    headers: {
      "Content-Type": "application/json",
      "x-auth-token": token,
    },
  });
  const data = await response.json();
  const name = data.name;

  // console.log(+iduser);
  // console.log(decoded);
  await fetch("/commentaires", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "x-auth-token": token,
    },
    body: JSON.stringify({
      email: email,
      contenu: comment,
      idarticle: idarticle,
      iduser: iduser,
    }),
  })
    .then((response) => {
      if (response.status == 200) {
        return response.json();
      } else {
        throw new Error("Something went wrong on api server!");
      }
    })
    .then((response) => {
      //we get the comment here so we need to add it to the comments array like this :
      comments.push(response);
      // let's start
      const commentOwner = document.createElement("h4");
      // commentOwner.setAttribute("style", "text-align:center");
      commentOwner.innerHTML = name;
      const p = document.createElement("p");
      p.setAttribute(
        "style",
        "text-align:center ; border-bottom:1px solid rgb(32, 178, 170, 0.9) ; margin-bottom:20px; padding-bottom : 10px ; line-height:1.8;"
      );
      p.innerHTML = response.contenu;
      const mainDivComments = document.querySelector(
        ".mainDivComments" + response.idarticle
      );
      mainDivComments.appendChild(commentOwner);
      mainDivComments.appendChild(p);
    })
    .catch((error) => {
      console.error("this is an error ", error.message);
    });
  emailInput.value = "";
  commentInput.value = "";
  commentForm.style.display = "none";
  const addcommentButon = document.querySelector(
    `.addcommentButon${idarticle}`
  );
  addcommentButon.style.display = "block";
};

var posts, users, comments;
// const myPagination = document.querySelector(".myPagination");
let fetchPosts = async (number, totalPages, thePosts, byCategories = 0) => {
  if (byCategories == 1 || totalPages == 1) {
    myPagination.innerHTML = "";
    for (let j = 0; j < thePosts.length; j++) {
      let post = thePosts[j];
      console.log("the post ", post);
      const { iduser, idarticle, title, content } = post;
      for (let i = 0; i < users.length; i++) {
        if (users[i].iduser == iduser) {
          var userName = users[i].name;
          break;
        }
      }
      var mainDivComments = `<div class="mainDivComments mainDivComments${idarticle}">`;
      let allComments = async () => {
        for (let i = 0; i < comments.length; i++) {
          if (comments[i].idarticle == idarticle) {
            const name = () => {
              for (let j = 0; j < users.length; j++) {
                if (users[j].iduser == comments[i].iduser) {
                  return users[j].name;
                }
              }
              return "";
            };
            if (name() == "") {
              continue;
            }
            let commentOwner = `<h4>${name()}</h4>`;
            mainDivComments += commentOwner;
            let p = `<p style="text-align:center ; border-bottom:1px solid rgb(32, 178, 170, 0.9) ; margin-bottom:20px; padding-bottom : 10px ; line-height:1.8;">${comments[i].contenu}</p>`;
            mainDivComments += p;
          }
        }
        mainDivComments += "</div>";
        let addcommentButon = `<button class="btn btn-primary addcommentButon${idarticle}" type="button" style="margin:0 auto ; display : block; width:fit-content ; background-color:rgb(32, 178, 170, 0.9);" onclick="addCommentForm(${post.idarticle});">Add Comment</button>`;
        mainDivComments += addcommentButon;
      };
      allComments();
      console.log(
        "mainDivComments",
        mainDivComments,
        "idarticle",
        idarticle,
        "usernmae",
        userName
      );
      myPagination.innerHTML += `<div class="card" style="max-width: 50rem; background-color: #fff ; margin : 10px auto;padding:0 10px 10px">
      <img src="http://picsum.photos/800/300?${iduser}" class="card-img-top" alt="...">
      <div class="card-body">
      <h3 class="card-title" >${userName}</h3>
        <h5 class="card-title" >${title}</h5>
        <p class="card-text">${content}</p>
      </div>
      <p>
      <button class="btn btn-primary" type="button" style="margin:0 auto ; display : block; width:fit-content ; background-color:rgb(32, 178, 170)" data-bs-toggle="collapse" data-bs-target="#collapseExample${post.idarticle}" aria-expanded="false" aria-controls="collapseExample">
      show comments
      </button>
      </p>
      <div class="collapse" id="collapseExample${post.idarticle}">
        <div class="card card-body">
      ${mainDivComments}
        </div> </div>
      </div>`;
    }
    console.log("myPagination fill ", myPagination);
  } else {
    //number represent the number of posts to show
    myPagination.innerHTML = "";
    document.body.style = "background-color:rgb(32, 178, 170, 0)";
    if (firstTime == true && localStorage.getItem("token") != null) {
      firstTime = false;
      comments = await fetch("/commentaires").then(async (response) => {
        let myData = await response.json();
        return myData;
      });
      users = await fetch("/users").then(async (response) => {
        let myData = await response.json();
        return myData;
      });
      posts = await fetch("/articles").then(async (response) => {
        let myData = await response.json();
        return myData;
      });
    }
    for (let j = number * 5 - 5; j < number * 5; j++) {
      // console.log(j);
      let post = posts[j];
      const { iduser, idarticle, title, content } = post;
      for (let i = 0; i < users.length; i++) {
        if (users[i].iduser == iduser) {
          userName = users[i].name;
          break;
        }
      }
      var mainDivComments =
        '<div class="mainDivComments mainDivComments' + idarticle + '">';
      // const mainDivComments = document.createElement("div");
      // mainDivComments.setAttribute("class", `mainDivComments${idarticle}`);
      let allComments = async () => {
        // console.log(comments);
        for (let i = 0; i < comments.length; i++) {
          if (idarticle == comments[i].idarticle) {
            const name = () => {
              // console.log(users);
              for (let k = 0; k < users.length; k++) {
                if (users[k].iduser == comments[i].iduser) return users[k].name;
              }
              return "";
            };
            if (name() == "") continue;
            let commentOwner = `<h4 style=''>${name()}</h4>`;
            mainDivComments += commentOwner;
            let p =
              "<p style='padding-left:10px; border-bottom:1px solid rgb(32, 178, 170, 0.9) ; margin-bottom:20px; padding-bottom : 10px ; line-height:1.8;'>";
            p += comments[i].contenu + "</p>";
            mainDivComments += p;
          }
        }

        mainDivComments += "</div>";
        //we need to add a comment form to write the email and the contenu//we need to make
        //we need to add a button in mainDive named add comment and when we click on it it will show the commentForm we will do it like this we add an event listener to the button and when we click on it we will change the display of the commentForm to block
        let addcommentButon = `<button class="btn btn-primary addcommentButon${idarticle}" type="button" style="margin:0 auto ; display : block; width:fit-content ; background-color:rgb(32, 178, 170, 0.9);" onclick="addCommentForm(${post.idarticle});">Add Comment</button>`;
        mainDivComments += addcommentButon;
      };
      allComments();

      myPagination.innerHTML += `<div class="card" style="max-width: 50rem; background-color: #fff ; margin : 10px auto;padding:0 10px 10px">
    <img src="http://picsum.photos/800/300?${iduser}" class="card-img-top" alt="...">
    <div class="card-body">
    <h3 class="card-title" >${userName}</h3>
      <h5 class="card-title" >${title}</h5>
      <p class="card-text">${content}</p>
    </div>
    <p>
    <button class="btn btn-primary" type="button" style="margin:0 auto ; display : block; width:fit-content ; background-color:rgb(32, 178, 170)" data-bs-toggle="collapse" data-bs-target="#collapseExample${post.idarticle}" aria-expanded="false" aria-controls="collapseExample">
    show comments
    </button>
    </p>
    <div class="collapse" id="collapseExample${post.idarticle}">
      <div class="card card-body">
    ${mainDivComments}
      </div> </div>
 
    </div>`;
      // const el = document.querySelector(".mainDivComments");
      // el.classList.add(`mainDivComments${idarticle}`);
    }
    // myPagination.style = "background-color:rgb(32, 178, 170, 0.3)";
    // document.body.style = "background-color:rgb(32, 178, 170, 0.09)";
  }
};

const hidAnimation = () => {
  loading.style.setProperty("display", "none");
};

const order = async (elm) => {
  await fetchPosts(1); //10 represent the page to be filled
  element.innerHTML = elm;
  // createPagination
  pagination.append(element);
  hidAnimation();
};

//end articles home

//navbar#############################

// function navbar() {
//   // Create the navBar element
//   const navBar = document.createElement("div");
//   navBar.classList.add("navBar");
//   navBar.style = "margin-top:10px";

function navbar() {
  // Create the navBar element
  const navBar = document.createElement("div");
  navBar.classList.add("navBar");
  // navBar.style.marginTop = "10px";
  navBar.style = "z-index: 1000;position: relative; height: 100px;";

  // Create the header element
  const header = document.createElement("div");
  header.classList.add("header");

  // Create the container element
  const container = document.createElement("div");
  container.classList.add("containerHeader");

  // Create the logo element
  const logo = document.createElement("div");
  logo.classList.add("logo");
  logo.style = "margin-left:25px";

  const logoImg = document.createElement("img");
  logoImg.src = "images/logo.png";
  logoImg.alt = "";
  logo.appendChild(logoImg);

  container.appendChild(logo);

  // Create the nav element
  const nav = document.createElement("div");
  nav.classList.add("nav");

  const barsIcon = document.createElement("i");
  barsIcon.classList.add("fa-solid", "fa-bars", "media");

  const ul = document.createElement("ul");
  ul.style = "margin:0";
  const navItems = ["HOME", "PROFILE", "CATEGORIES", "SETTINGS", "CONTACT"];

  navItems.forEach((item) => {
    const li = document.createElement("li");
    const a = document.createElement("a");
    a.href = `#${item}`;
    a.classList.add(`${item}`);
    a.classList.add("dropdown");
    li.classList.add(`${item}`);
    // a.textContent = item;
    const button = document.createElement("button");
    button.classList.add("btn", "btn-secondary", "dropdown-toggle");
    button.type = "button";
    button.setAttribute("data-bs-toggle", "dropdown");
    button.setAttribute("aria-expanded", "false");
    button.textContent = `${item}`;
    button.style = "border:none;background:none;margin:0";
    //when the button is hover do a click on it
    button.addEventListener("mouseover", () => {
      button.click();
    });
    a.appendChild(button);
    li.appendChild(a);
    ul.appendChild(li);
  });

  nav.appendChild(barsIcon);
  nav.appendChild(ul);

  // Create the search element
  const search = document.createElement("div");
  search.classList.add("search");

  const searchIcon = document.createElement("i");
  searchIcon.classList.add("fa-solid", "fa-magnifying-glass");

  search.appendChild(searchIcon);
  nav.appendChild(search);

  container.appendChild(nav);
  header.appendChild(container);
  navBar.appendChild(header);

  // Append the navBar element to the document body
  document.body.appendChild(navBar);
  categoriesListe();
  settingsListe();
}

function settingsListe() {
  const SETTINGS = document.querySelector("a.SETTINGS");
  const ul = document.createElement("ul");
  ul.classList.add("dropdown-menu");
  ul.style = "background: rgb(42,42,42,0.4);";
  const li = document.createElement("li");
  const a = document.createElement("a");
  a.classList.add("dropdown-item");
  a.href = `#`;
  a.textContent = "logout";
  li.appendChild(a);
  ul.appendChild(li);
  SETTINGS.appendChild(ul);
  li.addEventListener("click", logout);
}
async function categoriesListe() {
  const CATEGORIES = document.querySelector("a.CATEGORIES");
  const ul = document.createElement("ul");
  ul.classList.add("dropdown-menu");
  ul.style = "background: rgb(42,42,42,0.4);";
  const categories = await fetchCategories();
  categories.forEach((categorie) => {
    const li = document.createElement("li");
    li.classList.add(`${categorie.nom}`);
    //when the user click on the categorie we need to show the articles of this categorie
    li.addEventListener("click", () => {
      console.log("this is the idcategorie", categorie.idcategorie);
      fetchPostsByCategorie(categorie.idcategorie);
    });
    const a = document.createElement("a");
    a.classList.add("dropdown-item");
    a.href = `#${categorie.nom}`;
    a.textContent = categorie.nom;
    li.appendChild(a);
    ul.appendChild(li);
  });
  CATEGORIES.appendChild(ul);
}
async function fetchCategories() {
  return fetch("http://localhost:3000/categories")
    .then((response) => response.json())
    .then((data) => data);
}
var categories = fetchCategories();
async function fetchPostsByCategorie(id) {
  // we have the table of posts and the table of categories so we need just to filter the posts by categorie
  const categorie = await categories;
  // console.log(categories);
  console.log(categorie);

  // we will chose the categorie by id
  const theCategorie = categorie.filter(
    (categorie) => categorie.idcategorie === id
  );

  // we will chose the posts by categorie

  const thePosts = posts.filter(
    (post) =>
      post.articleCategorie[0].idcategorie === theCategorie[0].idcategorie
  );
  // we will show the posts if the posts are not empty
  if (thePosts.length !== 0) {
    const one = 1;
    const byCategories = 1;
    const elm = await createPagination(totalPages, page, byCategories);
    // console.log("first child", myPagination.firstChild);
    // myPagination.innerHTML = "";
    // console.log("first ", myPagination);
    // console.log("first child", myPagination.firstChild);
    while (myPagination.firstChild) {
      myPagination.removeChild(myPagination.firstChild);
      console.log("remove");
    }
    console.log("first child", myPagination);
    await fetchPosts(one, one, thePosts, byCategories);
    order(elm);
  } else {
    alert("there is no posts in this categorie");
  }
}

//we need to execute the function if the current page!= index.html
if (!window.location.href.match(/\/$|\/#$/)) {
  navbar();
}

//add article ###############

function addArticle() {
  // Create the addPostInput element
  const addArticleInput = document.createElement("div");
  addArticleInput.classList.add("addArticleInput");

  // Create the section element
  const section = document.createElement("section");

  // Create the profile image element
  const profileImage = document.createElement("img");
  profileImage.setAttribute("src", "../images/profile.webp");
  profileImage.setAttribute("width", "30px");
  profileImage.style = "border-radius: 50%;";
  profileImage.classList.add("userProfileImage");

  // Create the input element
  const input = document.createElement("input");
  input.setAttribute("id", "textInput");
  input.setAttribute("placeholder", "write something here");
  input.setAttribute("type", "text");
  input.setAttribute("maxlength", "80");

  //           <i class="fa-solid fa-magnifying-glass"></i>
  const i = document.createElement("i");
  i.setAttribute("class", "fa-solid fa-magnifying-glass");
  i.style =
    "font-size: 20px; color: #fff; position: absolute; right: 20px;font-weight: 900;";
  input.appendChild(i);

  // Append the profile image and input elements to the section element
  section.appendChild(profileImage);
  section.appendChild(input);

  // Create the POST button
  const articleAddButton = document.createElement("button");
  articleAddButton.classList.add("articleAddBtn");
  articleAddButton.setAttribute("type", "submit");
  articleAddButton.textContent = "Share";

  // Append the section and postButton elements to the addPostInput element
  addArticleInput.appendChild(section);
  addArticleInput.appendChild(articleAddButton);

  // Create the Posts element
  const articlesElement = document.createElement("div");
  articlesElement.setAttribute("id", "Posts");
  articlesElement.classList.add("Posts");
  return [addArticleInput, articlesElement];
}
