# webserv
*Tuesday, 13 August 2024*\
I've just finished a correction of webserv for another team. I realized the amount of work that we will have to do. It's a lot of work but incredibly interesting !\
## I asked the team your questions.
**How did they organize the work ?**\
They divided the work into 3 parts:
- Server, sockets and global structure of the code
- Location, parsing of the configuration file, html code, cgi
- Request, response, cgi sending

**Some ressouces other than the documentation ?**\
For the ressources, they mainly used the documentation but with the help of chatGPT. At the beginning, they give it paragraphs of the documentation and it gives them back a summary of it. After that, they used chatGPT to understand specific points of the documentation.\
I note some useful links that they gave me:\
https://www.codequoi.com/programmation-reseau-via-socket-en-c/ \
https://copyconstruct.medium.com/the-method-to-epolls-madness-d9d2d6378642 \
https://datatracker.ietf.org/doc/html/rfc1866

**Which tools did they use ?**\
They create an NGINX server (with Docker). Then they created a custom client to test the NGINX server and understand what it returns when they send a lot of different requests (crazy requests xD).\
**Additional tips:**\
Never store something from the client in a string beacause it can be contain '\0' and it will be a problem. Instead, use Vector of char.

I hope it will help us.