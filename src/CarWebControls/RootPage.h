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
    display: flex;
    flex-direction: column;
    justify-content: center;
  }
  button
  {
    font-size: 60px;
  }
  </style>
</head>
<body>
<div id="filldiv">
  <button type="button" id="turnLedOn">Turn led on</button>
  <button type="button" id="turnLedOff">Turn led off</button>
  <button type="button" id="toggleLed">Toggle led</button>

</div>
</body>

<script>
  document.getElementById("turnLedOn").addEventListener("click", () => fetch("/turnLedOn"));
  document.getElementById("turnLedOff").addEventListener("click", () => fetch("/turnLedOff"));
  document.getElementById("toggleLed").addEventListener("click", () => fetch("/toggleLed"));
</script>
</html>
)==";