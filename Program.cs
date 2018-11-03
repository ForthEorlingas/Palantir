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
                //podajemy dane dostępowe
                var credential = new NetworkCredential
                {
                    UserName = "krowadaria5",
                    Password = "zaq1@WSX"
                };
                client.Credentials = credential;

                //host oraz port poczty,
                //dostawca udostępnia nam te dane
                client.Host = "smtp.gmail.com";
                client.Port = 587;
                client.EnableSsl = true;

                //tworzymy wiadomość
                var message = new MailMessage();

                //dodajemy odbiorców
                message.To.Add(new MailAddress("oblivion114@wp.pl"));
                //podajemy adres nadawcy
                message.From = new MailAddress("krowadaria5@gmail.com");
                //Tytuł wiadomości
                message.Subject = "Raport";
                message.Body = "We have sent logs into yor email!";
                //Możemy uzyć znaczników html wewnątrz ciała wiadomości (parametr Body), w tym celu ustawiamy parametr na true
                message.IsBodyHtml = true;

                //Opcjonalnie możemy również dodać załącznik
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