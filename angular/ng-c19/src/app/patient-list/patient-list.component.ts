import { Component, OnInit } from '@angular/core';
import { Patient } from '../IPatient';
import { PatientService } from '../patient.service';

@Component({
  selector: 'app-patient-list',
  templateUrl: './patient-list.component.html',
  styleUrls: ['./patient-list.component.scss']
})
export class PatientListComponent implements OnInit {

  // public patients: any[] = [];
  public patients: Patient[] = [];
  public errorMsg: any;

  constructor(private _patientService: PatientService) { }

  ngOnInit(): void {}

  getGraph(){
    this._patientService.getPatients()
    .subscribe( data => this.patients = data );
  }

  async getGraphAsync(){
    this.patients = await this._patientService.getAsyncGraph();
  }

  // getPatient(){
  //   this.patients = this._patientService.getAsyncGraph();
  // }
}


