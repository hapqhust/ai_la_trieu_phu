<nav class="navbar navbar-expand-lg navbar-dark p-3", style="background-color: #092745;">
        <a class="navbar-brand" href="#">
            <img src="./prjltm.jpg" width="30" height="30" class="d-inline-block align-top" alt="">
        </a>
        <div class= "text-light">
        <?php 
                    session_start();
                    echo $_SESSION["username"] ;
            ?>
        </div>
        <div id="navb" class="navbar-collapse collapse hide text-light ">
            <ul class="nav navbar-nav ml-auto">
            <li class="nav-item mr-p5">
            <form action="home.php" method="post">
                    <input type="submit" class="nav-link text-dark " name ="home" value="HOME" >
                </form>
</li>
                <li class="nav-item">
                <form action="logout.php" method="post">
                    <input type="submit" class="nav-link text-dark" name ="logout" value="LOG OUT" >
                </form>
                </li>
            </ul> 
            
        </div>
</nav>
