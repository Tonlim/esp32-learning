/*
Contains the HTML of the root page.
*/
static const char* RootPage = R"==(
<html>
<head>
  <title>Toggle the led!</title>
</head>
<body>
  <h1 id="toggleTrigger">Press here to toggle the led!</h1>
</body>

<script>
  function toggle(e) {
    fetch("/toggleLed");
  }

  var toggleTrigger = document.getElementById("toggleTrigger");
  toggleTrigger.addEventListener("click", toggle);
</script>
</html>
)==";