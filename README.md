<h1>Minitalk</h1>
<h2>Overview</h2>
The Minitalk project involves developing a client-server communication system in the C programming language. Students are tasked with implementing a solution where a client can send messages to a server, employing advanced manipulation of system signals. Precise handling of signals, including the use of sigaction, is crucial to ensure reliable communication. The final result is an application that not only showcases students' proficiency in implementing distributed systems but also demonstrates their ability to handle critical aspects such as synchronization and error management.
<h2>How To Use</h2>
<ol>
  <li>Clone the repository:</li>
  <pre><code>git clone https://github.com/recozzi/minitalk_42.git</code></pre>
  <li>Move to the project's directory:</li>
  <pre><code>cd minitalk</code></pre>
  <li>Compile the source code with Makefile rule:</li>
  <pre><code>make</code></pre>
   <li>Now you are ready to use this Client-Server System:</li>
   Open two terminals. In the first one run the command:
   <pre><code>./server</code></pre>
   and in the second one run the client passing three arguments:
   <pre><code>./client server_pid message_you_want_to_send</code></pre>
</ol>
<h2>Info</h2>
For more information about this project, please read the subject file <a href="https://github.com/recozzi/minitalk_42/blob/main/en.subject.pdf">here</a>.
<h2>Licence</h2>
See <a href="https://github.com/recozzi/minitalk_42/blob/main/LICENSE">License</a>.
