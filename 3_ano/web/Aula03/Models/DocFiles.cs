using System.ComponentModel;

namespace Aula03.Models
{
    public class DocFiles
    {
        public List<FileViewModel> GetFiles(IHostEnvironment e)
        {
            List<FileViewModel> list = new List<FileViewModel>();
            DirectoryInfo DirInfo = new DirectoryInfo(Path.Combine(e.ContentRootPath,"wwwroot/Documents"));

            foreach(var file in DirInfo.GetFiles())
            {
                list.Add(new FileViewModel
                {
                    Name = file.Name,
                    Size = file.Length
                });

            }
            return list;

        }

    }
}
