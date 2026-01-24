/*
Contains the HTML of the root page.
*/
static const char* RootPage = R"==(
<html>
<head>
  <title>Car controls</title>
  <style>
  #filldiv
  {
    height: 70vh;
    width: 90vw;
  }

  button
  {
    font-size: 60px;
  }
  </style>
</head>
<body>
<div id="filldiv">
  <button type="button" id="toggleLed">Toggle led</button>
</div>
</body>

<script>
  document.getElementById("toggleLed").addEventListener("click", () => fetch("/toggleLed"));
</script>
</html>
)==";