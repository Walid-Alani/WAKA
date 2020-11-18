(function($) {

	"use strict";

	var fullHeight = function() {

		$('.js-fullheight').css('height', $(window).height());
		$(window).resize(function(){
			$('.js-fullheight').css('height', $(window).height());
		});

	};
	fullHeight();

	$('#sidebarCollapse').on('click', function () {
    $('#sidebar').toggleClass('active');
    var mylogoimg = document.getElementById("sidebar")
    if (mylogoimg.classList.contains("active")) {
      document.getElementById("myImg").src = "images/icon1.png";
      document.getElementById("myImg").style.width = "30px";
      document.getElementById("myImg").style.height = "30px";
      $('.logo').toggleClass('mr-2');
    } else{
      document.getElementById("myImg").src = "images/Tazmeen System Logo.png";
      document.getElementById("myImg").style.width = "140px";
      document.getElementById("myImg").style.height = "40px";
    }
  });

})(jQuery);


  var para = document.createElement("span");
      var node = document.createTextNode(
        "Home"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-1");
	  element.appendChild(para);
	  
	  var para = document.createElement("span");
      var node = document.createTextNode(
        "File"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-2");
	  element.appendChild(para);
	  
	  var para = document.createElement("span");
      var node = document.createTextNode(
        "Edit"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-3");
	  element.appendChild(para);
	  

	  var para = document.createElement("span");
      var node = document.createTextNode(
        "Character"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-4");
	  element.appendChild(para);
	  

	  var para = document.createElement("span");
      var node = document.createTextNode(
        "Search"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-5");
	  element.appendChild(para);
	  

	  var para = document.createElement("span");
      var node = document.createTextNode(
        "Video"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-6");
	  element.appendChild(para);
	  

	  var para = document.createElement("span");
      var node = document.createTextNode(
        "View"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-7");
	  element.appendChild(para);
	  

	  var para = document.createElement("span");
      var node = document.createTextNode(
        "Help"
      );
      para.appendChild(node);
      var element = document.getElementById("show-hide-text-8");
	  element.appendChild(para);



    var check = true;
    const widthOutput = document.querySelector('#width');

function reportWindowSize() {

  if ((window.innerWidth < 991.98) & (window.innerWidth > 540) & (check)) {
    $('#sidebar').toggleClass('active');
    check = false;
    document.getElementById("myImg").src = "images/icon1.png";
    document.getElementById("myImg").style.width = "30px";
    document.getElementById("myImg").style.height = "30px";
    $('.logo').toggleClass('mr-2');
  } else if ((window.innerWidth >= 991.98) | (window.innerWidth <= 540)) {
    check = true;
    var element = document.getElementById("sidebar");
    element.classList.remove("active");
    document.getElementById("myImg").src = "images/Tazmeen System Logo.png";
    document.getElementById("myImg").style.width = "140px";
    document.getElementById("myImg").style.height = "40px";
  } 
}

window.onresize = reportWindowSize;

if (element.classList.contains("active")) {
  
}





