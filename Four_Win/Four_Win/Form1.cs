using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Four_Win
{
    public partial class Main_frm : Form
    {
        Button[] Triangle_b_switch;

        /********** Red and Blue Files **********/
        Image switcher_red= Image.FromFile("arrow_red.png");
        Image switcher_blue = Image.FromFile("arrow_blue.png");

        int[] numbers = new int[7];

        Button[,] arr;
        DialogResult h;

        public Main_frm()
        {
            InitializeComponent();

            Triangle_b_switch = new Button[] {T_b1, T_b2, T_b3, T_b4, T_b5, T_b6, T_b7};

            arr = new Button[6, 7] {
                { C_00, C_01, C_02, C_03, C_04, C_05, C_06 },
                { C_10, C_11, C_12, C_13, C_14, C_15, C_16 },
                { C_20, C_21, C_22, C_23, C_24, C_25, C_26 },
                { C_30, C_31, C_32, C_33, C_34, C_35, C_36 },
                { C_40, C_41, C_42, C_43, C_44, C_45, C_46 },
                { C_50, C_51, C_52, C_53, C_54, C_55, C_56 }
            };

            for (int i = 0; i < 7; i++)  numbers[i] = 5;
        }

        private void Switch_Color_Btns(object sender, EventArgs e)
        {
            Button s = ((Button)sender);

            for (int i = 0; i < 7; i++)
                Tester(s, Triangle_b_switch[i], ref numbers[i], i);

            Check_Win(s);

            for (int i = 0; i < 7; i++)
                Tester_Triangle(s, Triangle_b_switch[i], ref numbers[i], i);
        }


        private void Tester(Button x, Button y, ref int max_row, int fixed_column)
        {
            if (x == y && max_row >= 0)
            {
                arr[max_row, fixed_column].Image = x.Image;
                arr[max_row, fixed_column].Text = (x.Image == switcher_red) ? "." : "..";
                arr[max_row, fixed_column].ForeColor = ColorTranslator.FromHtml((x.Image == switcher_red)? "#ff0000" : "#0000ff");
                max_row--;
            }
        }

        private void Tester_Triangle(Button x, Button y, ref int max_row, int fixed_column)
        {
            if (x == y && max_row >= 0)
            {
                x.Image = (x.Image == switcher_red) ? switcher_blue : switcher_red;

                foreach (Button item in Triangle_b_switch)
                    item.Image = x.Image;
            }
        }

        public void Check_Win(Button ww)
        {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (
                        ((j + 3) <= 6 && arr[i, j].Text == arr[i, j + 1].Text
                        && arr[i, j + 1].Text == arr[i, j + 2].Text
                        && arr[i, j + 2].Text == arr[i, j + 3].Text
                        && (arr[i, j].Text == "." || arr[i, j].Text == ".."))
                       )
                    {
                        Entire_retrycancel_dialog(h, ww);
                    }

                    Main_diameters(i, j, 5, 5, ww);
                    Main_diameters(i, j, 5, 4, ww);
                    Main_diameters(i, j, 5, 3, ww);
                    Main_diameters(i, j, 5, 6, ww);
                    Main_diameters(i, j, 4, 6, ww);
                    Main_diameters(i, j, 3, 6, ww);

                    if (
                        ((i + 3) <= 5 && arr[i, j].Text == arr[i + 1, j].Text
                        && arr[i + 1, j].Text == arr[i + 2, j].Text
                        && arr[i + 2, j].Text == arr[i + 3, j].Text
                        && (arr[i, j].Text == "." || arr[i, j].Text == ".."))
                       )
                    {
                        Entire_retrycancel_dialog(h, ww);
                    }

                    Revered_diameters(i, j, 3, 0, ww);
                    Revered_diameters(i, j, 4, 0, ww);
                    Revered_diameters(i, j, 5, 0, ww);
                    Revered_diameters(i, j, 5, 1, ww);
                    Revered_diameters(i, j, 5, 2, ww);
                    Revered_diameters(i, j, 5, 3, ww);
                }
            }
        }

        public void RetryCancel_DialogChecked(DialogResult z)
        {
            //if (z == DialogResult.Retry)
            //    for (int i = 0; i < 6; i++)
            //    {
            //        for (int j = 0; j < 7; j++)
            //        {
            //            arr[i, j].Image = null;
            //            arr[i, j].Text = null;
            //            numbers[j] = 5;
            //        }
            //    }
            //else Close();
        }

        public void Main_diameters (int i, int j, int last_r, int last_c, Button ww)
        {
            if ((j + 3) <= last_c && (i + 3) <= last_r)
            {
                if (
                (arr[i, j].Text == arr[i + 1, j + 1].Text
                && arr[i + 1, j + 1].Text == arr[i + 2, j + 2].Text
                && arr[i + 2, j + 2].Text == arr[i + 3, j + 3].Text
                && (arr[i, j].Text == "." || arr[i, j].Text == ".."))
                )
                {
                    Entire_retrycancel_dialog(h, ww);
                }
            }
        }

        public void Revered_diameters(int i, int j, int frist_r, int first_c, Button ww)
        {
            if ((j - 3) >= first_c && (i + 3) <= frist_r)
            {
                if (
                (arr[i, j].Text == arr[i + 1, j - 1].Text
                && arr[i + 1, j - 1].Text == arr[i + 2, j - 2].Text
                && arr[i + 2, j - 2].Text == arr[i + 3, j - 3].Text
                && (arr[i, j].Text == "." || arr[i, j].Text == ".."))
                )
                {
                    Entire_retrycancel_dialog(h, ww);
                }
            }
        }

        public void Entire_retrycancel_dialog(DialogResult p, Button k)
        {
            p = MessageBox.Show("The Winner is: " + ((k.Image == switcher_red) ? "Red" : "Blue") + "\n Would you like to try again?", "you win", MessageBoxButtons.RetryCancel, MessageBoxIcon.Information);
            //RetryCancel_DialogChecked(p);
            if(p == DialogResult.Retry)
                for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i, j].Image = null;
                    arr[i, j].Text = null;
                    numbers[j] = 5;
                }
            }
            else Close();
        }
    }
}
