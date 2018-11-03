using System;
using System.Net;
using System.Net.Mail;

namespace Mail
{
    class Program
    {
        static void Main(string[] args)
        {

            using (SmtpClient client = new SmtpClient())
            {

                var credential = new NetworkCredential
                {
                    UserName = "user",
                    Password = "password"
                };
                client.Credentials = credential;

                client.Host = "smtp.gmail.com";
                client.Port = 587;
                client.EnableSsl = true;


                var message = new MailMessage();

               
                message.To.Add(new MailAddress("email_1@wp.pl"));
               
                message.From = new MailAddress("email_2@gmail.com");
              
                message.Subject = "Raport";
                message.Body = "We have sent logs into yor email!";
               
                message.IsBodyHtml = true;


                Attachment a = new Attachment("D:\\screen.png", System.Net.Mime.MediaTypeNames.Image.Jpeg);
                message.Attachments.Add(a);
                message.Attachments.Add(new Attachment("D:\\xd.txt"));

                client.Send(message);
                Console.WriteLine("It's done!");
            }
            Console.ReadKey();
        }
    }
}
